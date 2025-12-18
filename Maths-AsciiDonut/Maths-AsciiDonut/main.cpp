#include <iostream>
#include <signal.h>
#include <windows.h> // For console settings

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "Light.h"

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void SetCursorVisible(bool visible)
{
    if (visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

void OnKill(int _signum)
{
    std::cout << "Liam ce gros bg :)\n";


    SetCursorVisible(true);
    exit(_signum);
}


int main(int argc, char** argv)
{
    signal(SIGINT, OnKill);

    InitConsole();
    ClearConsole();
    SetCursorVisible(false);

    Settings settings(argc, argv);
    Screen screen(settings);
    Light light(settings);

    screen.Display();
    Mesh mesh(settings);
    /*
    mesh.GenerateRectangle(10.f, 20.f);
    std::cout << "Rectangle 10x20:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateSquare(20.f);
    std::cout << "Square 20x20:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateCircle(15.f);
    std::cout << "Circle radius 15:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateHalfCircle(15.f);
    std::cout << "Half Circle radius 15:" << std::endl;
    screen.Display(mesh);
    */
    mesh.GenerateTorus(4.0f, 0.9);
    std::cout << "Torus Major 4, minor 0.9:" << std::endl;
    screen.Display(mesh, light);

    while (true)
    {
        mesh.Rotate(Axis::Y, settings.GetMeshRotationYPerAngle());
        mesh.Rotate(Axis::X, settings.GetMeshRotationXPerAngle());
        mesh.Rotate(Axis::Z, settings.GetMeshRotationZPerAngle());
        screen.Display(mesh, light);
        Sleep(settings.GetFrameDuration() / 1000);
        ClearConsole();
    }

    return 0;
}

// 2.5 : 
// La projection obtenue est etiree verticalement car un charactere est plus grand que large
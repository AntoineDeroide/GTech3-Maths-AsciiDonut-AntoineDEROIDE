#include <iostream>
#include <windows.h>

#include "Settings.h"
#include "Mesh.h"
#include "Screen.h"

// 1.1
int main(int argc, char** argv)
{
	//std::cout << "Hello World !\n";

// 1.2
	//std::cout << "Hello...\n";
	//std::cout << "\033[2J"; // console clear
	//std::cout << "...hello?\n";

	//std::cout << "\033[H"; // Move cursor to home position

	//std::cout << "\033[?25l"; // Make cursor invisible
	//std::cout << "\033[?25h"; // Make cursor visible

	//////////////////////////////////////////////////////////////////////
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);					//
	DWORD mode;															//
	GetConsoleMode(hConsole, &mode);									//
	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);//
	//////////////////////////////////////////////////////////////////////

// 1.3
	std::cout << "\033[?25l"; // Set cursor to invisible
	std::cout << "\033[2J"; // Clear console
	std::cout << "\033[H"; // cursor to home pos
	//std::cout << "Hello World !\n\n";

// 1.4
	/*unsigned short width = 100;
	unsigned short height = 20;
	char* vector = new char[width * height];

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			vector[i + j] = '.';

			std::cout << vector[i + j];
		}
		std::cout << '\n';
	}*/

// 1.5 / 1.6
// 1.7
// 2.1
// 2.2
// 2.3
	Settings settings(argc, argv);
	Screen screen(settings);
	Mesh circle(32); circle.GenerateCircle(5, Vertex(0,0,0));
	circle.Debug();
	Mesh halfcircle(32); halfcircle.GenerateHalfCircle(5, Vertex(0, 0, 0));
	halfcircle.Debug();
	Mesh rectangle(32); rectangle.GenerateRectangle(20, 10);
	rectangle.Debug();
	Mesh square(32); square.GenerateSquare(20);
	square.Debug();
}


#include <iostream>
#include <windows.h>

#include "Settings.h"
#include "Mesh.h"
#include "Screen.h"

// 1.1
int main(int argc, char** argv)
{
	Settings settings(argc, argv);
	Screen screen(settings);
	Mesh mesh(settings.GetResolution()); 
	mesh.MakeSquare(20);
	mesh.Debug();

	screen.Draw(mesh);
	screen.Display();
}


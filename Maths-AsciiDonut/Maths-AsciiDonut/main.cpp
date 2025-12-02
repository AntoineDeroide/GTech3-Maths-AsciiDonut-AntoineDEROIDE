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

// 2.5
// La projection est etireee verticalement car la surface occupee par un charactere est un rectangle 
// avec une longueur 2 fois plus grande que sa largeur
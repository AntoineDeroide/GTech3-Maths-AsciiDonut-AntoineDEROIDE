#include "Settings.h"
#include <iostream>

Settings::Settings(int argc, char** argv)
{
	if (argc < 5)
	{
		std::cout << "Not enough parameters to configure width and height of the display\n"
			<< "assigning default values\n";
		m_width = 100;
		m_height = 20;
		return;
	}
	// AsciiDonut.exe -w 3 -h 189
	if (argv[1] == "-w") m_width = atoi(argv[2]);
	if (argv[1] == "-h") m_height = atoi(argv[2]);

	// AsciiDonut.exe -h 35 -w 0983
	if (argv[3] == "-w") m_width = atoi(argv[4]);
	if (argv[3] == "-h") m_height = atoi(argv[4]);
}

int Settings::GetWidth()
{
	return m_width;
}

int Settings::GetHeight()
{
	return m_height;
}

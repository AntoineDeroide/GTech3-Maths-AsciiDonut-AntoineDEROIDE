#include "Settings.h"
#include <iostream>

Settings::Settings(int argc, char** argv) : m_width(100), m_height(20), m_resolution(32)
{
	if (argc < 5)
	{
		std::cout << "Not enough parameters to configure width and height of the display, assigning default values\n";
		return;
	}
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == "-w" && (i + 1) <= argc)
		{
			m_width = atoi(argv[i + 1]);
			i++;
		}
		if (argv[i] == "-w" && (i + 1) <= argc)
		{
			m_height = atoi(argv[i + 1]);
			i++;
		}
		if (argv[i] == "-r" && (i + 1) <= argc)
		{
			m_resolution = atoi(argv[i + 1]);
			i++;
		}
	}
}

int Settings::GetWidth()
{
	return m_width;
}

int Settings::GetHeight()
{
	return m_height;
}

int Settings::GetResolution()
{
	return m_resolution;
}

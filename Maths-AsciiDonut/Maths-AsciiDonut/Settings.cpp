#include "Settings.h"
#include <iostream>

Settings::Settings(int argc, char** argv) :
	m_width(100),
	m_height(20),
	m_resolution(32),
	m_screenPosition(3.33f),
	m_meshPosition(5.0f)
{
	if (argc < 5)
	{
		std::cout << "Not enough parameters to configure width and height of the display, assigning default values\n";
		return;
	}
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == "-w" && (i + 1) <= argc)
		{	// SCREEN WIDTH
			m_width = atoi(argv[i + 1]);
			i++;
		}
		if (argv[i] == "-h" && (i + 1) <= argc)
		{	// SCREEN HEIGHT
			m_height = atoi(argv[i + 1]);
			i++;
		}
		if (argv[i] == "-r" && (i + 1) <= argc)
		{	// MESH RESOLUTION
			m_resolution = atoi(argv[i + 1]);
			i++;
		}
		if (argv[i] == "-s" && (i + 1) <= argc)
		{	// SCREEN POSITION
			m_screenPosition = atof(argv[i + 1]);
			i++;
		}
		if (argv[i] == "-m" && (i + 1) <= argc)
		{	// MESH DISTANCE FROM SCREEN
			m_meshPosition = atof(argv[i + 1]);
			i++;
		}
		
		// DisplayedChar
		if (argv[i] == "-b" && (i + 1) <= argc)
		{	// BACKGROUND
			m_displayParameters[0] = argv[i + 1][0];
			i++;
		}
		if (argv[i] == "-p" && (i + 1) <= argc)
		{	// MESH PIXELS
			m_displayParameters[1] = argv[i + 1][0];
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

float Settings::GetScreenPosition()
{
	return m_screenPosition;
}

float Settings::GetMeshPosition()
{
	return m_meshPosition;
}

void Settings::SetBackgroundChar(char _c)
{
	m_background = _c;
}

char Settings::GetBackgroundChar()
{
	return m_background;
}

void Settings::SetMeshPixelChar(char _c)
{
	m_meshPixel = _c;
}

char Settings::GetMeshPixelChar()
{
	return m_meshPixel;
}
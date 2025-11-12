#include "Screen.h"
#include <iostream>

void Screen::Display(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << '.';
		}
		std::cout << '\n';
	}
}

void Screen::Display(const Mesh& mesh)
{
	
}

void Screen::Display(const Settings& settings)
{
	for (int i = 0; i < settings.m_height; i++)
	{
		for (int j = 0; j < settings.m_width; j++)
		{
			std::cout << '.';
		}
		std::cout << '\n';
	}
}

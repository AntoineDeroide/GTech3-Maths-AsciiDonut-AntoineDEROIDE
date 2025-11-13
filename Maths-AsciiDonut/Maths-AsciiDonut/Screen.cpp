#include "Screen.h"
#include <iostream>

Screen::Screen(const Settings& settings) : m_settings(settings)
{

}

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

void Screen::Display()
{
	for (int i = 0; i < m_settings.m_height; i++)
	{
		for (int j = 0; j < m_settings.m_width; j++)
		{
			std::cout << '.';
		}
		std::cout << '\n';
	}
}

#include "Screen.h"

#include <iostream>

Screen::Screen(const Settings& settings) : m_settings(settings)
{
	// code...
}

void Screen::Clear()
{
	std::cout << "\033[?25l"; // Set cursor to invisible
	std::cout << "\033[2J"; // Clear console
	std::cout << "\033[H"; // cursor to home pos
}

void Screen::Draw(const Mesh& mesh)
{
	// Parcourir le mesh, faire la projection de chaque point dans l'ecran

}

void Screen::Display(int width, int height)
{
	Clear();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << '.';
		}
		std::cout << '\n';
	}
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

Vertex Screen::MakeProjection(const Vertex& vertex)
{


	return Vertex(0.0f, 0.0f, 0.0f);
}

void Screen::Display(const Mesh& mesh)
{
	// Si l'on rencontre un point du mesh projeté, on affiche autre chose qu'un point
	for (int i = 0; i < m_settings.m_height; i++)
	{
		for (int j = 0; j < m_settings.m_width; j++)
		{
			std::cout << '.';
		}
		std::cout << '\n';
	}
}

#include "Mesh.h"
#include <iostream>

void Vertex::Debug()
{
	std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
}

Vertex::Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
	// code...
}

Mesh::Mesh(int resolution) : m_resolution(32)
{
	// code...
}

void Mesh::GenerateCube(float size)
{
	int x, y, z = 0;
	for (z; z < size * m_resolution; z++)
	{
		for (y; y < size * m_resolution; y++)
		{
			for (x; x < size * m_resolution; x++)
			{
				m_vertices.push_back(Vertex(x, y, z));
			}
		}
	}
}

void Mesh::GenerateSquare(float size)
{
	int x, y = 0;
	for (y; y < size * m_resolution; y++)
	{
		for (x; x < size * m_resolution; x++)
		{
			m_vertices.push_back(Vertex(x, y, 0));
		}
	}
}

void Mesh::GenerateRectangle(float width, float height)
{
	int x, y = 0;
	for (y; y < height * m_resolution; y++)
	{
		for (x; x < width * m_resolution; x++)
		{
			m_vertices.push_back(Vertex(x, y, 0));
		}
	}
}

void Mesh::GenerateCircle(float radius, const Vertex& center = Vertex(0.0f, 0.0f, 0.0f))
{
	float theta = 0.0f;

	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.1415 / 180;
		float point_x = center.x + radius * cos(theta);
		float point_y = center.y + radius * sin(theta);
		m_vertices.push_back(Vertex(point_x, point_y, center.z));
	}
}

void Mesh::GenerateHalfCircle(float radius, const Vertex& center = Vertex(0.0f, 0.0f, 0.0f))
{
	float theta = 0.0f;

	for (int i = 0; i < 180; i++)
	{
		theta = i * 3.1415 / 180;
		float point_x = center.x + radius * cos(theta);
		float point_y = center.y + radius * sin(theta);
		m_vertices.push_back(Vertex(point_x, point_y, center.z));
	}
}

void Mesh::Debug()
{
	for (Vertex i : m_vertices)
	{
		i.Debug();
	}
}

void Mesh::Update()
{
	m_resolution = m_vertices.size();

}


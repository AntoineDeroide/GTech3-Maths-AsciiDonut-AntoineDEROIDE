#include "Mesh.h"
#include "Screen.h"

#include <iostream>

// 
float PI = 3.141592653589793f;

void Vertex::Debug()
{
	std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
}

Vertex::Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
	// code...
}

void Vertex::Rotate(float _angle, Axis _axis)
{
	Vertex temp = *this;
	switch (_axis)
	{
	case(Axis::X):
		y = temp.y * cos(_angle) - temp.z * sin(_angle);
		z = temp.y * sin(_angle) + temp.z * cos(_angle);
		break;
	case(Axis::Y):
		x = temp.x * cos(_angle) + temp.z * sin(_angle);
		z = (-temp.x * sin(_angle)) + temp.z * cos(_angle);
		break;
	case(Axis::Z):		
		x = temp.x * cos(_angle) - temp.y * sin(_angle);
		y = temp.x * sin(_angle) + temp.y * cos(_angle);
		break;
	}
}

Mesh::Mesh(int resolution = 32) : m_resolution(resolution)
{
	// code...
}

void Mesh::MakeCube(float size)
{
	for (float z = 0; z < size * m_resolution; z++)
	{
		for (float y = 0; y < size * m_resolution; y++)
		{
			for (float x = 0; x < size * m_resolution; x++)
			{
				m_vertices.push_back(Vertex(x, y, z));
			}
		}
	}
}

void Mesh::MakeSquare(float size)
{
	for (float y = 0; y < size * m_resolution; y++)
	{
		for (float x = 0; x < size * m_resolution; x++)
		{
			m_vertices.push_back(Vertex(x, y, 0));
		}
	}
}

void Mesh::MakeRectangle(float width, float height)
{
	for (float y = 0; y < height * m_resolution; y++)
	{
		for (float x = 0; x < width * m_resolution; x++)
		{
			m_vertices.push_back(Vertex(x, y, 0));
		}
	}
}

void Mesh::MakeCircle(float radius, const Vertex& center = Vertex(0.0f, 0.0f, 0.0f))
{
	float theta = 0.0f;

	for (float i = 0; i < 360; i++)
	{
		theta = i * PI / 180;
		float point_x = center.x + radius * cos(theta);
		float point_y = center.y + radius * sin(theta);
		m_vertices.push_back(Vertex(point_x, point_y, center.z));
	}
}

void Mesh::MakeHalfCircle(float radius, const Vertex& center = Vertex(0.0f, 0.0f, 0.0f))
{
	float theta = 0.0f;

	for (int i = 0; i < 180; i++)
	{
		theta = i * PI / 180;
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

void Mesh::Rotate(float _angle, Axis _axis)
{
	for (Vertex& i : m_vertices)
	{
		i.Rotate(_angle, _axis);
	}
}

void Mesh::AddVertex(Vertex vertex)
{
	m_vertices.push_back(vertex);
}

void Mesh::Clear()
{
	m_vertices.clear();
}


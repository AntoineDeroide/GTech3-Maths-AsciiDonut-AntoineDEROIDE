#include "Mesh.h"
#include <iostream>

void Vertex::Debug()
{
	std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
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


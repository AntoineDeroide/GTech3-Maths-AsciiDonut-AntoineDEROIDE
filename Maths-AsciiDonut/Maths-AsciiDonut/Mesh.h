#pragma once
#include <vector>

struct Vertex
{
	float x, y, z;
	void Debug();
};

////////////////////////////

class Mesh
{
public:
	Mesh(int resolution);
	Mesh(const std::vector<Vertex>&);

	Mesh() = default;
	~Mesh() = default;

	void Debug();
	void Update();

private:
	std::vector<Vertex> m_vertices;
	int m_resolution;
};


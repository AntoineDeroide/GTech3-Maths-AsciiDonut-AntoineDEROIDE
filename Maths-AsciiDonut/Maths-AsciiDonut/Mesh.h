#pragma once
#include <vector>

struct Vertex
{
	float x, y, z;
	Vertex(float, float, float);
	void Debug();
};

////////////////////////////

class Mesh
{
public:
	Mesh(int resolution);
	Mesh(const std::vector<Vertex>&);

	~Mesh() = default;

	void GenerateCircle(float radius, const Vertex&);
	void GenerateHalfCircle(float radius, const Vertex&);
	void GenerateRectangle(float width, float height);
	void GenerateSquare(float size);

	void GenerateCube(float size);

	void Debug();
	void Update();

private:
	std::vector<Vertex> m_vertices;
	int m_resolution;
};


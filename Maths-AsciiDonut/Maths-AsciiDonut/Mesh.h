#pragma once
#include <vector>

enum Axis : char
{
	X = 'X',
	Y = 'Y',
	Z = 'Z'
};

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
	//Mesh(const std::vector<Vertex>&);

	~Mesh() = default;

	void MakeCircle(float radius, const Vertex&);
	void MakeHalfCircle(float radius, const Vertex&);
	void MakeRectangle(float width, float height);
	void MakeSquare(float size);
		 
	void MakeCube(float size);

	void Debug();
	void Update();

	void AddVertex(Vertex vertex);
	void Clear();

private:
	std::vector<Vertex> m_vertices;
	int m_resolution;
};


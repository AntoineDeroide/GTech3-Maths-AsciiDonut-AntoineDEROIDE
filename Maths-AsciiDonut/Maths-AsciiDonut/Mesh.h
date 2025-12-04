#pragma once
#include <vector>

enum class Axis : char
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
	void Rotate(float _angle, Axis _axis);
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
	void GenerateTorus(float _majorRadius, float _minorRadius);
		 
	void MakeCube(float size);

	void Debug();
	void Update();
	void Rotate(float _angle, Axis _axis);

	void AddVertex(Vertex vertex);
	void Clear();

private:
	std::vector<Vertex> m_vertices;
	int m_resolution;
};


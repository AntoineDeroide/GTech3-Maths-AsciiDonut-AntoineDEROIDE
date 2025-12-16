#include <cmath>
#include "Mesh.h"
#include "Settings.h"

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings const& settings)
    : m_resolution(settings.GetMeshResolution())
{
}

void Vertex::Rotate(Axis _axis, float _angle)
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

void Mesh::GenerateCircle(float radius)
{
    _GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    _GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            Vertex& current = m_vertices[m_resolution * i + j];

            current.x = (1.f * i / (m_resolution - 1) - 0.5f) * width;
            current.y = (1.f * j / (m_resolution - 1) - 0.5f) * height;
            current.z = 0.f;

        }
    }
}
void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}

void Mesh::GenerateTorus(float _majorRadius, float _minorRadius) // Major = distance avec l'axe | minor = rayon du cercle
{
    m_vertices.resize(m_resolution * m_resolution);
    float angleZ = 0;
    float angleY = 0;
    for (int i = 0; i < m_resolution; i++)
    {
        angleY = (2 * PI * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            angleZ = (2 * PI * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = _majorRadius + _minorRadius * cos(angleZ);
            m_vertices[m_resolution * i + j].y = _minorRadius * sin(angleZ);
            m_vertices[m_resolution * i + j].Rotate(Axis::Z, angleY);
        }
    }
}

void Mesh::Debug() const
{
    for (Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}

void Mesh::_GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            Vertex& current = m_vertices[m_resolution * i + j];
            float theta = (angle * j) / (m_resolution - 1);

            current.x = r * std::cos(theta);
            current.y = r * std::sin(theta);
            current.z = 0.f;

            // La normale fuit le centre de la figure ? Ou alors strictement perpendiculaire a la surface ?
            // Calcul de la normale : (x,y,z) / N avec N == sqrt(x**2 + y**2 + z**2)
            float normal = sqrtf(
                current.x * current.x + 
                current.y * current.y + 
                current.z * current.z
            );
            current.n.x = current.x / normal;
            current.n.y = current.y / normal;
            current.n.z = current.z / normal;
            // Ici, ca peut fonctionner si le cercle est centre a l'origine
        }
    }
}

void Mesh::Rotate(Axis _axis, float _angle)
{
    for (Vertex& i : m_vertices)
    {
        i.Rotate(_axis, _angle);
    }
}
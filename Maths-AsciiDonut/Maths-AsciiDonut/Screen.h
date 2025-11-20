#include "Settings.h"
#include "Mesh.h"

#include <vector>

class Screen
{
public:
	Screen() = default;
	Screen(const Settings&);
	~Screen() = default;

	void Clear();
	void Draw(const Mesh&);

	void Display(int width, int height);
	void Display();

private:
	Vertex MakeProjection(const Vertex& vertex);
	void Display(const Mesh& mesh);
	Settings m_settings;


	friend class Mesh;
};


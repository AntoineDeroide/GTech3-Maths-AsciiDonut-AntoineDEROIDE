#include "Settings.h"

class Mesh;

class Screen
{
public:
	Screen() = default;
	Screen(const Settings&);
	~Screen() = default;

	void Display(int width, int height);
	void Display();
	void Display(const Mesh&);

private:
	Settings m_settings;

};


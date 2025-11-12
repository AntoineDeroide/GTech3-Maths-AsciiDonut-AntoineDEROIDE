#include "Settings.h"

class Mesh;

class Screen
{
public:
	Screen();
	Screen(const Settings&);
	~Screen();

	void Display(int width, int height);
	void Display(const Settings&);
	void Display(const Mesh&);

private:
	Settings m_settings;

};


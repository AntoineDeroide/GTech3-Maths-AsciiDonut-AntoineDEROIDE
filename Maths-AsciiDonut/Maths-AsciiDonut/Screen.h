#include "Settings.h"


class Screen
{
public:
	Screen();
	Screen(const Settings&);
	~Screen();

private:
	Settings m_settings;

};


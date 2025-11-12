#pragma once

class Settings
{
public:
	Settings(int argc, char** argv);

	int GetWidth();
	int GetHeight();
	int GetResolution();

private:
	int m_width, m_height, m_resolution;
};


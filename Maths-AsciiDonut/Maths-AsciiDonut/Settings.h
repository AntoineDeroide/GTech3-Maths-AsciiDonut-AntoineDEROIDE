#pragma once

enum DisplayedChar : char
{
	BACKGROUND_CHAR = ' ',
	PROJECTION_CHAR = 'X',
};

class Settings
{
public:
	Settings(int argc, char** argv);

	int GetWidth();
	int GetHeight();
	int GetResolution();
	int GetScreenPosition();
	int GetMeshPosition();

private:
	int m_width;
	int m_height;
	int m_resolution;
	float m_screenPosition;
	float m_meshPosition;

	char m_displayParameters[2]; // 0 == background ; 1 == mesh pixels

	friend class Screen;
};


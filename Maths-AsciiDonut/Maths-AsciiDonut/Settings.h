#pragma once

class Settings
{
public:
	Settings(int argc, char** argv);

	int GetWidth();
	int GetHeight();
	int GetResolution();
	float GetScreenPosition();
	float GetMeshPosition();

	void SetBackgroundChar(char _c);
	char GetBackgroundChar();
	
	void SetMeshPixelChar(char _c);
	char GetMeshPixelChar();

private:
	int m_width;
	int m_height;
	int m_resolution;
	float m_screenPosition;
	float m_meshPosition;

	char m_background;
	char m_meshPixel;

	friend class Screen;
};


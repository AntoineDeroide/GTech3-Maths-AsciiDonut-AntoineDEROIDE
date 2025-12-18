#pragma once

class Settings;

class Light
{
	float x, y, z;
	float nx, ny, nz;

public:
	Light(Settings const& _settings);
	~Light() = default;

	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetZ() const { return z; }

	float GetNormalizedLight();
};


#include "Light.h"
#include "Settings.h"

Light::Light(Settings const& _settings)
{
	x = _settings.GetLightXDir();
	y = _settings.GetLightYDir();
	z = _settings.GetLightZDir();




}
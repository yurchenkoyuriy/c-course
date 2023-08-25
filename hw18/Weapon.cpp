#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
	if (distance > 2000)
	{
		return 0.2f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 5.0f;
	}
	return 1.0f;
}

float Pistol::getPrecision(int distance) const
{
	if (distance > 150)
	{
		return 0.2f;
	}
	if (distance > 70)
	{
		return 0.8f;
	}
	if (distance > 20)
	{
		return 2.0f;
	}
	return 3.0f;
}

float Shotgun::getPrecision(int distance) const
{
	if (distance > 50)
	{
		return 0.1f;
	}
	if (distance > 35)
	{
		return 1.0f;
	}
	if (distance > 25)
	{
		return 3.5f;
	}
	return 8.0f;
}

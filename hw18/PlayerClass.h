#pragma once
#include <string>

class PlayerClass
{
	//FEEL free to add other unique properties
public:
	virtual ~PlayerClass() = default;

	virtual float getDamageMultiplier() const = 0;
	virtual float getDefenseMultiplier() const = 0;
};

class DefaultClass : public PlayerClass
{
	virtual float getDamageMultiplier() const override { return 1.0f; }
	virtual float getDefenseMultiplier() const override { return 1.0f; }
};

class DefenderClass : public DefaultClass
{
public:
	//Leave damage multiplier as is
	virtual float getDefenseMultiplier() const override { return 1.1f; }
};

class AttackerClass : public DefaultClass
{
	float getDamageMultiplier() const override { return 1.1f; }
};
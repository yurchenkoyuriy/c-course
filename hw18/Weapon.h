#pragma once
#include <string>

class Player;

class Weapon
{
public:	
	virtual ~Weapon() = default;
	virtual std::string getName() const = 0;
	virtual int getDamageRate(int distance, int speed) const = 0;
};

class RangedWeapon : public Weapon
{
public:	
	int getDamageRate(int distance, int speed = 0) const override { return static_cast<int>(getPrecision(distance + speed) * 10); }
	
protected:	
	virtual float getPrecision(int distance) const { return 1.0f; }	
};

class SniperRifle : public RangedWeapon
{
public:
	std::string getName() const override { return "SniperRifle"; }

protected:	
	virtual float getPrecision(int distance) const override;
};

class Pistol : public RangedWeapon
{
public:
	std::string getName() const override { return "Pistol"; }

protected:
	virtual float getPrecision(int distance) const override;
};

class Shotgun : public RangedWeapon
{
public:
	std::string getName() const override { return "Shotgun"; }

protected:
	virtual float getPrecision(int distance) const override;
};

class MeleeWeapon : public Weapon
{
public:	
	int getDamageRate(int distance, int speed = 0) const override { return (speed >= distance) ? static_cast<int>(getDamage() * attackSpeed()) : 0; }
	virtual int attackSpeed() const = 0;

protected:
	virtual float getDamage() const { return 1.0f; }
};

class BareHand : public MeleeWeapon
{
public:
	std::string getName() const override { return "BareHand"; }

protected:
	virtual float getDamage() const override { return 3.0f; };
	int attackSpeed() const override { return 3; }
};

class Knife : public MeleeWeapon
{
public:	
	std::string getName() const override { return "Knife"; }

protected:
	virtual float getDamage() const override { return 8.0f; };
	int attackSpeed() const override { return 2; }
};

class Axe : public MeleeWeapon
{
public:
	std::string getName() const override { return "Axe"; }

protected:
	virtual float getDamage() const override { return 20.0f; };
	int attackSpeed() const override { return 1; }
};
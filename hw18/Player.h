 #pragma once
#include <string>
#include<iostream>
#include "PlayerClass.h"
#include "Weapon.h"

class Player
{
public:
	Player(const std::string& name = "Auto Generated NameId", Weapon* weapon = new BareHand, PlayerClass* playerClass = new DefaultClass, int speed = 50)
		: m_name(name), m_weapon(weapon), m_class(playerClass), m_speed(speed) {}
	~Player()
	{
		delete m_class;
		delete m_weapon;
	}


	std::string getName() const { return m_name; }
	std::string getHealth() { return std::to_string(m_health); }
	int getBaseDamage(int distance) { return m_weapon->getDamageRate(distance, m_speed); }
	int getSpeed() const { return m_speed; }
	void setSpeed(const int speed) { m_speed = speed; }

	void setWeapon(Weapon* weapon);
	void setPlayerClass(PlayerClass* playerClass);
	void setHealth(int health) { m_health = health; }
	void takingDamage(int damage) { m_health -= damage; }
	bool isEliminated() const { return m_health <= 0; }

	void attack(Player& other, int distance);

private:
	int m_health = 100;
	std::string m_name;
	int m_speed;
	PlayerClass* m_class = nullptr;
	Weapon* m_weapon = nullptr;
};
#include <iostream>
#include "Player.h"
#include "Team.h"


void Player::addWeapon(std::string name, int damage, int range)
{
	weapon.name = name;
	weapon.damage = damage;
	weapon.range = range;
}

void Player::printPlayerInfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "HP: " << healPoint << std::endl;
    this->printSpeciality();
	std::cout << "Weapon name: " << weapon.name << std::endl;
	std::cout << "Weapon damage: " << weapon.damage << std::endl;
	std::cout << "Weapon range: " << weapon.range << std::endl;

	if (team != nullptr)
	{
		std::cout << "Team: " << team->comandName << std::endl;
	}

	std::cout << std::endl;
}

void Player::printSpeciality()
{
    std::cout << "Speciality: ";

    switch (speciality)
        {
        case Speciality::assault:
            std::cout << "assault";
            break;
        case Speciality::support:
            std::cout << "support";
            break;
        case Speciality::sniper:
            std::cout << "sniper";
            break;
        case Speciality::medic:
            std::cout << "medic";
            break;
    }

    std::cout << std::endl;
}
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Weapon.h"

enum Speciality 
{
    assault = 1,
    support,
    sniper,
    medic
};

class Team;

class Player
{
public:
    Player()
        : name("Player"), healPoint(100), speciality(Speciality::assault)
    {
    }

    Player(std::string name_arg, int healPoint_arg, Speciality speciality_arg)
        : name(name_arg), healPoint(healPoint_arg), speciality(speciality_arg) 
    {
    }

    std::string name;
    int healPoint;
    Speciality speciality;
    Weapon weapon;
    Team* team = nullptr;

    void addWeapon(std::string name, int damage, int range);
    void printPlayerInfo();
    void printSpeciality();
};

#endif // PLAYER_H
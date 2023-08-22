#include <iostream>
#include <string>

class Weapon
{
public:
    Weapon() 
        : name("wooden stick"), damage(1), range(1)
    {
    }

    Weapon(std::string name_arg, int damage_arg, int range_arg)
        : name(name_arg), damage(damage_arg), range(range_arg)
    {
    }

    void updateWeapon(std::string arg_name, int arg_damage, int arg_range) {
        name = arg_name;
        damage = arg_damage;
        range = arg_range;
    }

    void printWeaponInfo() const {
        std::cout << "Weapon name: " << name << std::endl;
        std::cout << "Weapon damage: " << damage << std::endl;
        std::cout << "Weapon range: " << range << std::endl;
    }

private:
    std::string name;
    int damage;
    int range;
};
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

    std::string name;
    int damage;
    int range;
};
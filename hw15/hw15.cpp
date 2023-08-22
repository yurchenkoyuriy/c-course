#include <iostream>
#include "Rectangle.h"
#include "Team.h"


int main()
{
    // Task 1
    Rectangle rect1(3.2f, 4.2f);
    Rectangle rect2(4.3f, 6.2f);

    std::cout << "Area rect1: " << rect1.getArea() << std::endl;
    std::cout << "Perimeter rect1: " << rect1.getPerimeter() << std::endl;
    std::cout << "Area rect2: " << rect2.getArea() << std::endl;
    std::cout << "Perimeter rect2: " << rect2.getPerimeter() << std::endl << std::endl;

    // Task 2
    Player player("Stan Marsh", 100, Speciality::medic);
    player.addWeapon("sword of a thousand truths", 5000000, 1);
    player.printPlayerInfo();    

    // Task 3
    Team team("South park team");
    Player player2("Eric Cartman", 100, Speciality::sniper);

    team.addPlayer(&player);
    team.addPlayer(&player2);

    std::cout << "Add " << player.getName() << " and " << player2.getName() << " to " << team.getTeamName() << " team." << std::endl;

    player.printPlayerInfo();
    player2.printPlayerInfo();

    std::cout << "Remove " << player.getName() << " from " << team.getTeamName() << " team." << std::endl;

    team.removePlayer(&player);

    player.printPlayerInfo();
    player2.printPlayerInfo();
}

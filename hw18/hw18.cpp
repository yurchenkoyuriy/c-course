#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
	//Game cycle
	Player player1("OnePunchMan", new SniperRifle);
	Player player2("JohnCena", new Axe, new DefenderClass);
	Player player3("Altair", new Knife, new AttackerClass);
	player3.setSpeed(1000);
	Player player4("Aang", new BareHand, new DefenderClass);
	player4.setSpeed(100);
	Player player5("bum with a shotgun", new Shotgun);	

	player3.attack(player1, 500);
	player3.attack(player2, 500);
	player1.attack(player2, 500);
	player1.attack(player2, 2000);
	player1.attack(player1, 300);
	player2.attack(player1, 51);
	player1.attack(player2, 500);
	player4.attack(player3, 1000);
	player4.attack(player3, 100);
	player4.attack(player3, 1);
	player5.attack(player1, 100);
	player5.attack(player1, 50);
	player5.attack(player1, 20);

	

	return 0;
}
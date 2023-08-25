#include "Player.h"

void Player::setWeapon(Weapon* weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
	delete m_class;
	m_class = playerClass;
}

void Player::attack(Player& other, int distance)
{
	if (&other == this)
	{
		std::cout << "\n-------FRIENDLY FIRE!-------\n";
	}

	if (other.isEliminated())
	{
		std::cout << "Player " << other.getName() << " has been already eliminated!\n";
		return;
	}

	//#TODO: Optional: Add your own damage-related modifier
	const int damage = static_cast<int>(m_weapon->getDamageRate(distance, m_speed) * m_class->getDamageMultiplier() / other.m_class->getDefenseMultiplier());
	other.takingDamage(damage);

	std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
		" with weapon " << m_weapon->getName() << " with damage " << damage << std::endl;

	std::cout << "Player " << other.getName() << " has Health left : " << other.getHealth() << std::endl;

	if (other.isEliminated())
	{
		other.setHealth(0);
		std::cout << "Player " << other.getName() << " was eliminated!\n";
	}
}
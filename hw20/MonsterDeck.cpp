#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"
#include "Victory.h"

MonsterDeck::MonsterDeck()
{
	loadDatabase();
}

MonsterDeck::~MonsterDeck()
{
	//TODO: Clear memory
}

Monster* MonsterDeck::generateMonster()
{
	if (m_monstersDatabase.size() == 0)
	{
		loadDatabase();
	}

	const int idx = std::rand() % m_monstersDatabase.size();
	Monster* monster = m_monstersDatabase[idx];
	m_monstersDatabase.erase(m_monstersDatabase.begin() + idx);
	return monster;
}

void MonsterDeck::loadDatabase()
{
	m_monstersDatabase =
	{
		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
		new Monster{"Crazy Joe", 422, Tribe::Human, new Runaway_ItemEquipedRemoval, new Victory_ExtraLevels},
		new Monster{"Spanch Bob", 1, Tribe::God, new Runaway_ItemEquipedRemoval, new Victory_AddModifierToHand},
		new Monster{"Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}, new Victory_AddItemEquiped},
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_ItemEquipedRemoval, new Victory_AddItemEquiped}
	};
}
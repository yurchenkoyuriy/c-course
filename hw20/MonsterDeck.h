#pragma once
#include <vector>

class Monster;

class MonsterDeck
{
public:
	MonsterDeck();
	~MonsterDeck();

	Monster* generateMonster();
	void loadDatabase();

private:
	std::vector<Monster*> m_monstersDatabase;
};
#include "ItemDeck.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>


ItemDeck::ItemDeck()
{
	loadDatabase();
}

ItemDeck::~ItemDeck()
{
	for (Item* item : m_itemsDataBase)
	{
		delete item;
	}

	m_itemsDataBase.clear();
}

Item* ItemDeck::generateItem()
{
	if (m_itemsDataBase.size() == 0)
	{
		loadDatabase();
	}

	unsigned int idx = std::rand() % m_itemsDataBase.size();
	Item* item = m_itemsDataBase[idx];
	m_itemsDataBase.erase(m_itemsDataBase.begin() + idx);
	return item;
}


std::vector<Item*> ItemDeck::generateItems(int startItems)
{
	std::vector<Item*> userItems;
	for (int i = 0; i < startItems; i++)
	{
		userItems.push_back(generateItem());
	}

	return userItems;
}

void ItemDeck::loadDatabase()
{
	std::ifstream inputFile("itemsDatabase.txt");

	if (!inputFile.is_open()) {		
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string type, name;
		int power;

		if (std::getline(iss, type, ';') &&
			std::getline(iss, name, ';') &&
			(iss >> power)) {
			Item* el = createItem(type, name, power);
			if (el != nullptr)
			{
				m_itemsDataBase.push_back(el);
			} 
			else
			{
				delete el;
			}
		}
	}

	inputFile.close();
}

Item* ItemDeck::createItem(std::string type, std::string name, int power)
{
	std::transform(type.begin(), type.end(), type.begin(), [](unsigned char c) { return std::tolower(c); });

	if (type == "weapon")
	{
		return new Weapon{ name, power };
			
	} 
	else if (type == "undeadweapon")
	{
		return new UndeadWeapon{ name, power };
		
	}
	else if (type == "ragnarokweapon")
	{
		return new RagnarokWeapon{ name, power };
	}	

	return nullptr;
}
#pragma once
#include <vector>
#include <string>

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	Item* generateItem();
	std::vector<Item*> generateItems(int startItems = 3);	

private:
	void loadDatabase();
	Item* createItem(std::string type, std::string name, int power);
	std::vector<Item*> m_itemsDataBase;
};
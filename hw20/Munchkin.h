#pragma once
#include <vector>
#include <string>

class Item;
class Modifier;

using uint = unsigned int;

class Munchkin
{
public:
	Munchkin() = default;
	Munchkin(const std::string& name) : m_name(name) {}

	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	int getLevel() const { return m_level; }
	void updateLevelBy(int levels);

	void addItem(Item* item);
	void addItems(const std::vector<Item*>& items);
	const std::vector<Item*>& getItems() const;

	void removeRandomModifierFromHand();
	void removeBestItemEquipped();

	Modifier* popModifier(int idx);
	const std::vector<Modifier*>& getModifiers() const { return m_modifiers; }
	void addModifier(Modifier* modifiers) { m_modifiers.push_back(modifiers); }
	void addModifiers(const std::vector<Modifier*>& modifiers) { m_modifiers = modifiers; }	

private:
	uint m_level = 1;
	std::string m_name;

	std::vector<Item*> m_items;
	std::vector<Modifier*> m_modifiers;
};
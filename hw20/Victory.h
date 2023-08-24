#pragma once
#include <string>

class Munchkin;
class ModifierDeck;
class ItemDeck;

class Victory
{
public:
	virtual void apply(Munchkin* munchkin, ModifierDeck* modifierDeck, ItemDeck* itemDeck) = 0;
    virtual std::string getFullInfo() const { return ""; }
};

class Victory_ExtraLevels : public Victory
{
public:
	Victory_ExtraLevels(int level = 1) : m_levelToUpgrade(level) {}
	void apply(Munchkin* munchkin, ModifierDeck* modifierDeck = nullptr, ItemDeck* itemDeck = nullptr) override;
	std::string getFullInfo() const override { return "Extra " + std::to_string(m_levelToUpgrade) + " level(s)."; }

protected:
	int m_levelToUpgrade;
};

class Victory_AddModifierToHand : public Victory
{
public:
	void apply(Munchkin* munchkin, ModifierDeck* modifierDeck, ItemDeck* itemDeck = nullptr) override;
	std::string getFullInfo() const override { return "Get a new modifier."; }
};

class Victory_AddItemEquiped : public Victory
{
public:
	void apply(Munchkin* munchkin, ModifierDeck* modifierDeck, ItemDeck* itemDeck) override;
	std::string getFullInfo() const override { return "Get a new item equiped."; }
};
#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;
	virtual std::string getFullInfo() const { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() const override { return "Lose " + std::to_string(m_levelToDowngrade) + " level(s)."; }

protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel)
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() const override { return "Lose 1 level if your level is below " + std::to_string(m_minimalMunchkinLevelToApply) + "."; }

private:
	int m_minimalMunchkinLevelToApply;
};

class Runaway_ModifierFromHandRemoval : public Runaway
{
public:	
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() const override { return "Lose random modifier from your hand."; }
};

class Runaway_ItemEquipedRemoval : public Runaway
{
public:	
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() const override { return "Lose your best equipment."; }
};
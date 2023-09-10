#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
	loadDatabase();
}

ModifierDeck::~ModifierDeck()
{
	for (Modifier* modifier : m_modifiersDatabase)
	{
		delete modifier;
	}
}

Modifier* ModifierDeck::generateModifier()
{
	if (m_modifiersDatabase.size() == 0)
	{
		loadDatabase();
	}

	unsigned int idx = std::rand() % m_modifiersDatabase.size();
	Modifier* modifier = m_modifiersDatabase[idx];
	m_modifiersDatabase.erase(std::remove_if(m_modifiersDatabase.begin(), m_modifiersDatabase.end(),
		[modifier](const Modifier* m) { return m == modifier; }), m_modifiersDatabase.end());

	return modifier;
}

std::vector<Modifier*> ModifierDeck::generateModifiers(int startModifiers)
{
	std::vector<Modifier*> userModifier;
	for (int i = 0; i < startModifiers; i++)
	{
		userModifier.push_back(generateModifier());
	}
	
	return userModifier;
}

void ModifierDeck::loadDatabase()
{
	m_modifiersDatabase =
    {
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{4}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::God}}
	};
}
#pragma once
#include <vector>

//forward declaration to not include header into header which will increase compilation time
class Modifier;

class ModifierDeck
{
public:
	ModifierDeck();
	~ModifierDeck();

	Modifier* generateModifier();
	void loadDatabase();

	std::vector<Modifier*> generateModifiers(int startModifiers = 9);	

private:
	std::vector<Modifier*> m_modifiersDatabase;
};
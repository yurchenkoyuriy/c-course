#include "Victory.h"
#include "Munchkin.h"
#include "ModifierDeck.h"
#include "ItemDeck.h"

void Victory_ExtraLevels::apply(Munchkin* munchkin, ModifierDeck* modifierDeck, ItemDeck* itemDeck)
{
	munchkin->updateLevelBy(m_levelToUpgrade);
}

void Victory_AddModifierToHand::apply(Munchkin* munchkin, ModifierDeck* modifierDeck, ItemDeck* itemDeck)
{
	munchkin->addModifier(modifierDeck->generateModifier());
}

void Victory_AddItemEquiped::apply(Munchkin* munchkin, ModifierDeck* modifierDeck, ItemDeck* itemDeck)
{
	munchkin->addItem(itemDeck->generateItem());
}


#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
        m_level += levels;
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::addItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;

}


void Munchkin::removeRandomModifierFromHand() 
{
    if (m_modifiers.size() == 0)
    {
        return;
    }

    unsigned int idx = std::rand() % m_modifiers.size();
    m_modifiers.erase(m_modifiers.begin() + idx);
}

void Munchkin::removeBestItemEquipped()
{
    if (m_items.size() == 0)
    {
        return;
    }

    int power = 0;
    int idx = 0;
        
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        if (m_items[i]->getBasePower() > power)
        {
            power = m_items[i]->getBasePower();
            idx = i;
        }
    }

    m_items.erase(m_items.begin() + idx);
}

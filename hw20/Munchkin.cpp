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
    std::swap(m_modifiers[idx], m_modifiers.back());
    m_modifiers.pop_back();
}

void Munchkin::removeBestItemEquipped()
{
    if (m_items.empty())
    {
        return;
    }

    auto maxItemIt = std::max_element(m_items.begin(), m_items.end(),
        [](const Item* item1, const Item* item2)
        {
            return item1->getBasePower() < item2->getBasePower();
        });

    if (maxItemIt != m_items.end())
    {
        m_items.erase(std::remove_if(m_items.begin(), m_items.end(),
            [maxItemIt](const Item* item)
            {
                return item == *maxItemIt;
            }), m_items.end());
    }
}

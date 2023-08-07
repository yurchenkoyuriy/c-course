#include "Team.h"

void Team::addPlayer(Player* player)
{
    if (player == nullptr)
    {
        return;
    }

    players[m_currentEmptyPlace] = player;
    players[m_currentEmptyPlace]->team = this;
    m_currentEmptyPlace++;
}


void Team::removePlayer(Player* player)
{
    for (int i = 0; i < m_currentEmptyPlace; ++i)
    {        
        if (players[i] == player) 
        {
            players[i]->team = nullptr;
            for (int j = i; j < m_currentEmptyPlace - 1; ++j) 
            {
                players[j] = players[j + 1];
            }
            m_currentEmptyPlace--;
            break;
        }
    }
}

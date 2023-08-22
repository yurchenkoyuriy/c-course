#include "Team.h"

void Team::addPlayer(Player* player)
{
    if (player == nullptr) { return; }

    players.push_back(player);
    players[players.size() - 1]->setTeam(this);
}


void Team::removePlayer(Player* player)
{
    for (int i = 0; i < players.size(); ++i)
    {        
        if (players[i] == player) 
        {
            players.erase(players.begin() + i);
            break;
        }
    }
}

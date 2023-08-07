#include <string>
#include "Player.h"

class Team
{
public:
    Team()
        : comandName("Player"), sizeTeam(0)
    {
    }

    Team(std::string comandName_arg)
        : comandName(comandName_arg)
    {
        sizeTeam = 0;
    }

    std::string comandName;
    int sizeTeam;

    void addPlayer(Player* player);
    void removePlayer(Player* player);

private:
    int m_currentEmptyPlace = 0;        
    Player* players[10] = { nullptr };
};

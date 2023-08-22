#include <vector>
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
    
    void addPlayer(Player* player);
    void removePlayer(Player* player);
    std::string getTeamName() const { return comandName; };

private:
    std::string comandName;
    int sizeTeam;     
    std::vector<Player*> players;
};

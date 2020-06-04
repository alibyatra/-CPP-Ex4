#include "SniperCommander.hpp"
 
namespace WarGame 
{
    SniperCommander::SniperCommander(int team) : Sniper(team) 
    {
        setFullHP(120);
        HP = getFullHP();
        damage = 100;
        commander = true;
    }

    SniperCommander::~SniperCommander() {}

    void SniperCommander::activate(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location)
    {
        Sniper::activate(board, location);
    }
};
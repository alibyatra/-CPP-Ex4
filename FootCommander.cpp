#include "FootCommander.hpp"

namespace WarGame
{
    void FootCommander::activate(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location)
    {
        FootSoldier::activate(board, location);
    }

    FootCommander::FootCommander(int team) : FootSoldier(team) 
    {
        setFullHP(150);
        HP = getFullHP();
        damage = 20;
        commander = true;
    }
    FootCommander::~FootCommander() {}
};
#include "ParamedicCommander.hpp"

namespace WarGame 
{
    void ParamedicCommander::activate(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location)
    {
        Paramedic::activate(board, location);
    }

    ParamedicCommander::ParamedicCommander(int team) : Paramedic(team) 
    {
        setFullHP(200);
        HP = getFullHP();
        commander = true;
    }

    ParamedicCommander::~ParamedicCommander() {}
};

#pragma once
#include "Soldier.hpp"

class Paramedic : public virtual Soldier
{
    public:
        Paramedic(int playerID): Soldier(playerID, 100, 0){}
        Paramedic() : Soldier(0, 0, 0) {}
        void activate(vector<vector<Soldier *>> &board, pair<int, int> location);
};

#pragma once
#include "Soldier.hpp"

class Sniper : public virtual Soldier
{
    public:
        Sniper(int playerID): Soldier(playerID, 100, 50){}
        Sniper() : Soldier(0,0,0) {}
        void activate(vector<vector<Soldier*>> &board, pair<int,int> location);
};
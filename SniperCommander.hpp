#pragma once
#include "Sniper.hpp"

class SniperCommander : public Sniper
{
    public:
        SniperCommander(int playerID): Soldier(playerID, 120, 100){}
        void activate(vector<vector<Soldier*>> &board, pair<int,int> location);
        void activateC(vector<vector<Soldier *>> &board, pair<int, int> location);
};
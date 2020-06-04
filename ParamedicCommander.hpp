#pragma once
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic
{
    public:
        ParamedicCommander(int playerID) : Soldier(playerID, 200, 0){}
        void activate(vector<vector<Soldier*>> &board, pair<int,int> location);
        void activateC(vector<vector<Soldier *>> &board, pair<int, int> location);
};
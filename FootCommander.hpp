#pragma once
#include "FootSoldier.hpp"	

class FootCommander : public FootSoldier
{
	public:
        FootCommander(int playerID) : Soldier(playerID, 150, 20) {}
        void activate(vector<vector<Soldier *>> &board, pair<int, int> location);
        void activateC(vector<vector<Soldier *>> &board, pair<int, int> location);
};
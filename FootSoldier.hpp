#pragma once
#include "Soldier.hpp"

class FootSoldier : public virtual Soldier
{
	public:
		FootSoldier(int playerID): Soldier(playerID, 100, 10){}
		FootSoldier() : Soldier(0,0,0){}
        void activate(vector<vector<Soldier*>> &board, pair<int,int> location);
};
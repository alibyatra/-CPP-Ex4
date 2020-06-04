#pragma once
#include "Soldier.hpp"

namespace WarGame 
{
	class FootSoldier : public Soldier
	{
		public:
			FootSoldier(int team);
			~FootSoldier();
        	void activate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
	};
};
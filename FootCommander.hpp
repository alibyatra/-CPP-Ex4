#pragma once
#include "FootSoldier.hpp"	

namespace WarGame 
{
        class FootCommander : public FootSoldier
        {
	public:
                FootCommander(int team);
                ~FootCommander();
                void activate(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location);
        };
};
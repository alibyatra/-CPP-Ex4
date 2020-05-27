#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"	

namespace WarGame
{
    class FootCommander : public FootSoldier{

	public:
		 FootCommander(uint player): FootSoldier(player){
		HP += 50;
		FullHP += 50;
		damage += 10;
	}
	  void activate(int x, int y, Board& board_f) override;
};
}
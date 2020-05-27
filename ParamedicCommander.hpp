#pragma once
#include <string>
#include <stdexcept>
#include <vector>
#include "Paramedic.hpp"

namespace WarGame
{
    class ParamedicCommander : public Paramedic{

        public:
        ParamedicCommander(uint player): Paramedic(player){
			FullHP += 100;
			HP += 100;
		}
        void activate(int x, int y, Board& board_f) override;
    };
}
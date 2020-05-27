#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame
{
    class Sniper : public Soldier{
        protected:

        public:
        Sniper(uint player): Soldier(player, 100, 50){}
        void activate(int x, int y, Board& board_f) override;
    };

} 
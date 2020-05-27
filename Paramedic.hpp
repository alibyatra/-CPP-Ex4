#pragma once
#include <string>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame
{
    class Paramedic : public Soldier{
        protected:

        public:
        Paramedic(uint player): Soldier(player, 100){}
        void activate(int x, int y, Board& board_f) override;
    };
}
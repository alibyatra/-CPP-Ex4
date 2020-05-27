#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"

namespace WarGame
{
    class SniperCommander : public Sniper{

        public:
        SniperCommander(uint player): Sniper(player){
            FullHP += 20;
            HP += 20;
            damage += 50;
            }
        void activate(int x, int y, Board& board_f) override;  
    };

} 
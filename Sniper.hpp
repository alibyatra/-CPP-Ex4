#pragma once
#include "Soldier.hpp"

namespace WarGame
{
    class Sniper : public Soldier
    {
        public:
            Sniper(int team);
            ~Sniper();
            void activate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
    };
};
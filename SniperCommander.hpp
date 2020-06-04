#pragma once
#include "Sniper.hpp"

namespace WarGame
{
    class SniperCommander : public Sniper
    {
        public:
            SniperCommander(int team);
            void activate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
            ~SniperCommander();
    };
};
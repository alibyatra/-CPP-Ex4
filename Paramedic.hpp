#pragma once
#include "Soldier.hpp"

namespace WarGame 
{
    class Paramedic : public Soldier
    {
        public:
            Paramedic(int team);
            ~Paramedic();
            void activate(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location);
    };
};

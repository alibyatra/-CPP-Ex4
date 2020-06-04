#pragma once
#include "Paramedic.hpp"

namespace WarGame 
{
    class ParamedicCommander : public Paramedic
    {
        public:
            ParamedicCommander(int team);
            ~ParamedicCommander();
            void activate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
    };   
};
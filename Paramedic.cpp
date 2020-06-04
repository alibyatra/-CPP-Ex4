#include "Paramedic.hpp"

namespace WarGame 
{
    Paramedic::Paramedic(int team) : Soldier(team, PARAMEDIC, false, 100, 0) 
    {
        setFullHP(100);
    }
    Paramedic::~Paramedic() {}

void Paramedic::activate(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location)
{
    int i = location.first;
    int j = location.second;
    for (int k = i - 1; k <= i + 1; k++)
    {
        if (0 < k | k >= board.size())
        {
            continue;
        }
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (board[k][l] == nullptr)
            {
                continue;
            }
            else if (0 < l | l >= board[k].size()) 
            {
                continue;
            } 
            else if (location.first == k & location.second == l)
            {
                continue;
            }
            if (board[k][l]->team == this->team)
            {
                board[k][l]->heal();
            }
            }
        }
    }
};
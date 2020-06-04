#include "FootSoldier.hpp"

namespace WarGame 
{
    FootSoldier::FootSoldier(int team) : Soldier(team, FOOT, false, 100, 10) 
    {
        setFullHP(100);
    }
    FootSoldier::~FootSoldier() {}

    void FootSoldier::activate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) 
    {
        Soldier *temp = nullptr;
        int min = 2000000000;
        std::pair<int,int> goal (location);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
            if (board[i][j] == nullptr)
            {
              continue;
            } 
            else if (board[i][j]->team == this->team) 
            {
                continue;
            }  
            if (abs(location.first - i) + abs(location.second - j) < min) 
            {
                min = abs(location.first - i) + abs(location.second - j);
                goal = {i,j};
            }
            }
        }
        if (!board[goal.first][goal.second]->commander)
        {
            board[goal.first][goal.second]->HP -= 10;
        } 
        else 
        {
            board[goal.first][goal.second]->HP -= 20;
        }

        if (board[goal.first][goal.second]->HP <= 0) 
        {
            Soldier* dead = board[goal.first][goal.second];
            board[goal.first][goal.second] = nullptr;
            delete dead;
        }
    }
};
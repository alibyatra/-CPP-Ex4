#include "Sniper.hpp"

namespace WarGame 
{
    Sniper::Sniper(int team) : Soldier(team, SNIPER, false, 100, 50) 
    {
        setFullHP(100);
    }

    Sniper::~Sniper() {}

    void Sniper::activate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)
    {
    std::pair<int,int> goal (location);
    int strongest = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == nullptr)
            {
                continue;
            }
            else if (board[i][j]->team == team)
            {
                continue;
            }
            if (board[i][j]->HP > strongest)
            {
                strongest = board[i][j]->HP;
                goal = {i,j};
            }
        }
    }
    if (!board[goal.first][goal.second]->commander) 
    {
        board[goal.first][goal.second]->HP -= 50;
    } 
    else
    {
        board[goal.first][goal.second]->HP -= 100;
    }
    if (board[goal.first][goal.second]->HP <= 0)
    {
        Soldier* dead = board[goal.first][goal.second];
        board[goal.first][goal.second] = nullptr;
        delete dead;
    }
    }
};
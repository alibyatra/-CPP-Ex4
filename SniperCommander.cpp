#include "SniperCommander.hpp"

void SniperCommander::activate(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Sniper::activate(board, location);
    activateC(board, location);
}

void SniperCommander::activateC(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *sol = board[i][j];
            if (sol != nullptr && sol->getPlayerNum() == getPlayerNum())
            {
                if (dynamic_cast<Sniper*>(sol) && !dynamic_cast<SniperCommander*>(sol))
                {
                    sol->activate(board, {i, j});
                }
            }
        }
    }
}
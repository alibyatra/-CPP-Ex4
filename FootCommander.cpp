#include <iostream>
#include <vector>
#include "FootCommander.hpp"

void FootCommander::activate(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    FootSoldier::activate(board, location);
    activateC(board, location);
}

void FootCommander::activateC(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            Soldier *sol = board[i][j];
            if (sol != nullptr && sol->getPlayerNum() == getPlayerNum())
            {
                if (dynamic_cast<Soldier*>(sol) && !dynamic_cast<FootCommander*>(sol)) 
                    sol->activate(board, {i,j});
            }
        }
    }
} 
#include "ParamedicCommander.hpp"

void ParamedicCommander::activate(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Paramedic::activate(board, location);
    activateC(board, location);
}
void ParamedicCommander::activateC(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *sol = board[i][j];
            if (sol != nullptr && sol->getPlayerNum() == getPlayerNum())
            {
                if (dynamic_cast<Paramedic*>(sol) && !dynamic_cast<ParamedicCommander*>(sol))
                {
                    sol->activate(board, {i, j});
                }
            }
        }
    }
}
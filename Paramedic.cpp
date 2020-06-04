#include "Paramedic.hpp"

void Paramedic::activate(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    int i = location.first;
    int j = location.second;
    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (k >= 0 && k < board.size() && l >= 0 && l < board[0].size())
            {
                Soldier *sol = board[k][l];
                if (sol != nullptr && sol->getPlayerNum() == getPlayerNum())
                {
                    if (!(k == i && l == j))
                    sol->setHealth(sol->getFullHealth());
                }
            }
        }
    }
}
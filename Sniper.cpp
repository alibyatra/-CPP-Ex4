#include <iostream>
#include "Sniper.hpp"

void Sniper::activate(vector<vector<Soldier*>> &board,pair<int,int> location)
{
    Soldier *temp = nullptr;
    int strongest = 0;
    int one, two;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *sol = board[i][j];
            if (sol != nullptr && sol->getPlayerNum() != getPlayerNum())
            {
                if (sol->getHealth() > strongest)
                {
                    strongest = sol->getHealth();
                    temp = sol;
                    one = i;
                    two = j;
                }
            }
        }
    }
    if (temp != nullptr)
    {
        temp->setHealth(temp->getHealth() - getDamage());
        if (temp->getHealth() <= 0)
        {
            board[one][two] = nullptr;                
        }
    }
}
#include "FootSoldier.hpp"
#include <bits/stdc++.h>

double distance(pair<int, int> location1, pair<int, int> location2)
    {
        int first = location2.first - location1.first;
        int sec = location2.second - location1.second;
        return sqrt(pow(first, 2) + pow(sec, 2) * 1.0);    
    }

void FootSoldier::activate(vector<vector<Soldier*>> &board,pair<int,int> location) 
{
    Soldier *temp = nullptr;
    double closest = distance({0, 0},{board.size(), board[0].size()});
    int one,two;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *sol = board[i][j];
            pair<int, int> solLoc;
            solLoc.first = i;
            solLoc.second = j;
            if (sol != nullptr && sol->getPlayerNum() != getPlayerNum())
            {
                double dis = distance(location, solLoc);
                if (dis < closest)
                {
                    closest = distance(location, solLoc);
                    temp = sol;
                    one=i;
                    two=j;
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
#include "Soldier.hpp"
#include "FootSoldier.hpp"

namespace WarGame 
{
    Soldier::Soldier(uint team, uint type, bool commander, int HP, int damage) 
    {
        this->team = team;
        this->type = type;
        this->commander = commander;
        this->HP = HP;
        this->damage = damage;
    }

    Soldier::~Soldier() {}

    int Soldier::getFullHP() const 
    {
        return FullHP;
    }

    void Soldier::setFullHP(int FullHP)
    {
        this->FullHP = FullHP;
    }

    void Soldier::heal() 
    {
        HP = getFullHP();
    }

    void Soldier::activateTogether(std::vector<std::vector<Soldier*>>& board) 
    {
        if (!commander)
        {
            return;
        }
        for (int i = 0; i < board.size(); i++) 
        {
            for (int j = 0; j < board[i].size(); j++) 
            {
                if (board[i][j] == nullptr) 
                {
                    continue;
                } 
                else if (board[i][j]->commander) 
                {
                    continue;
                } 
                else if (board[i][j]->team != team) 
                {
                    continue;
                }
                else if (board[i][j]->type != type) 
                {
                    continue;
                }
                activate(board, std::pair<int,int> {i,j});
            }
        }
    }
};
#pragma once
#include <cmath>
#include <vector>
#include <iostream>

#define FOOT 0
#define SNIPER 1
#define PARAMEDIC 2

namespace WarGame 
{
  class Soldier 
  {
    private:
      int FullHP;

    public:
        uint team;
        uint type;
        bool commander;
        int HP;
        int damage;

        Soldier(uint team, uint type, bool commander, int HP, int damage);

        virtual ~Soldier();

        int getFullHP() const;

        void setFullHP(int FullHP);

        void heal();

        virtual void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) = 0;

        void activateTogether(std::vector<std::vector<Soldier*>>& board);
    };
};
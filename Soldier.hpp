#pragma once
#include <vector>
#include <stdexcept>
#include <math.h>

using namespace std;

class Soldier
{
  private:
    int player;
    int FullHP;
    int HP;
    int damage;
    
  public:
    Soldier(int playerID, int H, int d) : player(playerID), HP(H), FullHP(H), damage(d) {}
    virtual int getHealth() {return HP;}
    virtual int getPlayerNum(){ return player;}
    virtual int getFullHealth() {return FullHP;}
    virtual int getDamage() {return damage;}
    void setHealth(int H) {HP = H;}
    virtual void activate(vector<vector<Soldier *>> &board, pair<int, int> location){};
    virtual ~Soldier() {}
};
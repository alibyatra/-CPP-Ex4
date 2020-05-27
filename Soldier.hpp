#ifndef SOLDIER_HPP_
#define SOLDIER_HPP_
#include <string>
#include <vector>
#include <stdexcept>

namespace WarGame
{
  class Board;

  class Soldier
  {
  protected:
    uint player;
    uint FullHP;
    int HP;
    uint damage;
 

  public:
    Soldier(uint playerID, uint h, uint p = 0) : player(playerID), FullHP(h), HP(h), damage(p) {}
    double distance(int x1, int y1, int x2, int y2);
    bool heal();
    int getHealth() {return HP;};
    void hurm(uint i);
    int getPlayerNum(){ return player;}
    virtual void activate(int x, int y, Board& board_f) = 0;
    virtual void printSoldier();
    
  };

} 
#endif 
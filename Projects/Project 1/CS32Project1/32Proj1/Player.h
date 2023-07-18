//
//  Player.hpp
//  32Proj1
//
//  Created by Anthony Chen on 4/8/23.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Arena;

class Player
{
  public:
      // Constructor
    Player(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    string dropPoisonedCarrot();
    string move(int dir);
    void   setDead();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};

#endif /* Player_hpp */

//
//  Rabbit.hpp
//  32Proj1
//
//  Created by Anthony Chen on 4/8/23.
//

#ifndef Rabbit_hpp
#define Rabbit_hpp

#include "History.h"
#include <stdio.h>

class Arena;  // This is needed to let the compiler know that Arena is a
              // type name, since it's mentioned in the Rabbit declaration.

class Rabbit
{
  public:
      // Constructor
    Rabbit(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    void move();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
    //History m_history;
};

#endif /* Rabbit_hpp */

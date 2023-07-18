//
//  Game.hpp
//  32Proj1
//
//  Created by Anthony Chen on 4/8/23.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Arena;

class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    string takePlayerTurn();
};

#endif /* Game_hpp */

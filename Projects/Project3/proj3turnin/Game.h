//
//  Game.hpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.h"
#include "Player.h"
#include "Side.h"

class Game{
public:
    Game(const Board& b, Player* south, Player * north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move(Side s);
    void play();
    int beans(Side s, int hole);
    
private:
    Board m_board;
    Player* m_south;
    Player* m_north;
    Side m_turn;
};

#endif /* Game_hpp */

//
//  Game.cpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#include "Game.h"
#include <iostream>

Game::Game(const Board& b, Player* south, Player * north)
: m_board(b), m_turn(SOUTH)
{
    m_south = south;
    m_north = north;
    
}

void Game::display() const{
    std::cout << "  " << m_north->name() << std::endl;
    std::cout << " ";
    for(int i = 1; i <= m_board.holes(); i++){
        std::cout << m_board.beans(NORTH, i) << " ";
    }
    std::cout << std::endl;
    std::cout << m_board.beans(NORTH, 0);
    std::cout << " ";
    for(int i = 1; i < m_board.holes(); i++){
        std::cout << "  ";
    }
    std::cout << m_board.beans(SOUTH, 0) << std::endl;
    std::cout << " ";
    for(int i = 1; i <= m_board.holes(); i++){
        std::cout << m_board.beans(SOUTH, i) << " ";
    }
    std::cout << std::endl;
    std::cout << "  " << m_south->name() << std::endl;
}

void Game::status(bool& over, bool& hasWinner, Side& winner) const{
    if(m_board.beansInPlay(NORTH) != 0 && m_board.beansInPlay(SOUTH) != 0){
        // there are still beans in play
        over = false;
        return;
    } else {
        // the game is over
        if(m_board.beans(NORTH, 0) + m_board.beansInPlay(NORTH) > m_board.beans(SOUTH, 0)+ m_board.beansInPlay(SOUTH)){
            // north win
            over = true;
            hasWinner = true;
            winner = NORTH;
        } else if(m_board.beans(NORTH, 0) + m_board.beansInPlay(NORTH) < m_board.beans(SOUTH, 0) + m_board.beansInPlay(SOUTH)){
            // south win
            over = true;
            hasWinner = true;
            winner = SOUTH;
        } else if(m_board.beans(NORTH, 0) + m_board.beansInPlay(NORTH) == m_board.beans(SOUTH, 0) + m_board.beansInPlay(SOUTH)){
            // draw
            over = true;
            hasWinner = false;
        }
        over = true;
    }
}

bool Game::move(Side s){
    bool over;
    bool winner;
    Side side;
    status(over, winner, side);
    
    int hole_choice;
    int endhole;
    bool sow_result;
    
    if(over){
        return false;
    }
    
    if(s == SOUTH){
        // south side
        if(m_board.beansInPlay(SOUTH) == 0){
            // meaning that the game is done
            over = true;
            return false;
        }
        hole_choice = m_south->chooseMove(m_board, SOUTH);
        if(!(m_south->isInteractive())){
            std::cout << m_south->name() << " chose hole " << hole_choice << std::endl;
            std::cout << std::endl;

        }
        sow_result = m_board.sow(SOUTH, hole_choice, side, endhole);
        if(!sow_result){
            // invalid move
            move(SOUTH);
        }
        if(sow_result && endhole == 0){
            display();
            std::cout << m_south->name() << " gets another turn." << std::endl;
            move(SOUTH);
        } else {
            if(m_board.beans(SOUTH, endhole) == 1 && side == SOUTH && m_board.beans(NORTH, endhole) != 0){
                // capturing
                m_board.moveToPot(SOUTH, endhole, SOUTH);
                m_board.moveToPot(NORTH, endhole, SOUTH);
            }
            m_turn = NORTH;
        }
        
        
    } else if (s == NORTH){
        if(m_board.beansInPlay(NORTH) == 0){
            // meaning that the game is done
            over = true;
            return false;
        }
        hole_choice = m_north->chooseMove(m_board, NORTH);
        if(!(m_north->isInteractive())){
            std::cout << m_north->name() << " chose hole " << hole_choice << std::endl;
            std::cout << std::endl;

        }
        sow_result = m_board.sow(NORTH, hole_choice, side, endhole);
        if(!sow_result){
            // invalid move
            move(NORTH);
        }
        if(sow_result && endhole == 0){
            display();
            std::cout << m_north->name() << " gets another turn." << std::endl;
            move(NORTH);
        } else {
            if(m_board.beans(NORTH, endhole) == 1 && side == NORTH && m_board.beans(SOUTH, endhole) != 0){
                // capturing
                m_board.moveToPot(SOUTH, endhole, NORTH);
                m_board.moveToPot(NORTH, endhole, NORTH);
            }
            // switch turn
            m_turn = SOUTH;
        }
    }

    return true;
}

void Game::play(){
    bool over = true;
    bool win;
    Side winner;
    display();
    status(over, win, winner);
    while(!over){
        move(m_turn);
        display();
        status(over, win, winner);
    }
        // move all beans to pot if it is over, sweep board
        for(int i = 1; i <= m_board.holes(); i ++){
            m_board.moveToPot(NORTH, i, NORTH);
            m_board.moveToPot(SOUTH, i, SOUTH);
        }
        display();
        if(winner == NORTH){
            std::cout << "The winner is " << m_north->name() << std::endl;
        } else if(winner == SOUTH){
            std::cout << "The winner is " << m_south->name() << std::endl;
        } else {
        std::cout << "The game ends in a tie.";
        }
}

int Game::beans(Side s, int hole){
    return m_board.beans(s, hole);
}

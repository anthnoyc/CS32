//
//  Player.hpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Board.h"
#include "Side.h"

//========================================================================
// Timer t;                 // create and start a timer
// t.start();               // restart the timer
// double d = t.elapsed();  // milliseconds since timer was last started
//========================================================================

#include <chrono>

class Timer
{
  public:
    Timer()
    {
        start();
    }
    void start()
    {
        m_time = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const
    {
        std::chrono::duration<double, std::milli> diff =
                          std::chrono::high_resolution_clock::now() - m_time;
        return diff.count();
    }
  private:
    std::chrono::high_resolution_clock::time_point m_time;
};

//========================================================================



class Player{
public:
    Player(std::string name);
    std::string name() const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
private:
    std::string m_name;
};


class HumanPlayer: public Player{
public:
    HumanPlayer(std::string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
    virtual ~HumanPlayer();
    
private:
    
};


class BadPlayer: public Player{
public:
    BadPlayer(std::string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
    virtual ~BadPlayer();
private:
};


class SmartPlayer: public Player{
public:
    SmartPlayer(std::string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
    virtual ~SmartPlayer();
    
    
    int minimax(const Board &b, Side s, int &best_hole, int &value, const int depth, const int original_depth, Timer t) const;
    int eval(Board b, Side s) const;
    int sow_and_capture(Board &b, Side s, int hole, Side &endSide) const;

private:
};


#endif /* Player_hpp */

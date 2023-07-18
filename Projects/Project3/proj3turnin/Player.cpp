//
//  Player.cpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//
#include <iostream>
#include "Player.h"

Player::Player(std::string name){
    m_name = name;
}

std::string Player::name() const{
    return m_name;
}

bool Player::isInteractive() const{
    return false; // TO DO
}

Player::~Player(){
    
}

// HUMAN PLAYER ------------------------------------------------------------------------------------
HumanPlayer::HumanPlayer(std::string name)
:Player(name) {
    
}

bool HumanPlayer::isInteractive() const{
    return true;
}

int HumanPlayer::chooseMove(const Board& b, Side s) const{
    // this is just getting the inputs for a proper move
    // no beans to move
    if(b.beansInPlay(s) == 0){
        return -1;
    }
    int move = -1;
    // infinite loop with a break
    bool not_possible = true;
    while(not_possible){
        // each time it is not true, then repeat
        std::cout << "Select a hole, " << Player::name() << ": ";
        std::cin >> move;
        std::cout << std::endl;
        
        if(move >= 0 && move <= b.holes() && b.beans(s, move) > 0){
            // valid hole choice
            not_possible = false;
        }
        if(move <= 0 || move > b.holes()){
            std::cout << "The hole number must be in between 1 and " << b.holes() << "." << std::endl;
        }
        if(b.beans(s, move) <= 0){
            std::cout << "There are no beans in that hole." << std::endl;
        }
        // then repeat
    }
    // if invalid then want to return -1
    return move; // TO DO
}

HumanPlayer::~HumanPlayer(){
    
}


// BAD PLAYER ------------------------------------------------------------------------------------

BadPlayer::BadPlayer(std::string name)
:Player(name) {
    
}
bool BadPlayer::isInteractive() const{
    return false;
}
// does not need isInteractive since it is in the virtual
int BadPlayer::chooseMove(const Board& b, Side s) const{
    if(b.beansInPlay(s) == 0) {
        return -1;
    }
    int move = 1;
    int result = -1;
    while(move <= b.holes()){
        if(b.beans(s, move) > 0){
            result = move;
            break;
        }
        if(b.beans(s, move) <= 0){
            // if it is not a valid hole, then increase the chosen hole by 1
            move ++;
        }
    }
    return result;
}

BadPlayer::~BadPlayer(){
    
}

// SMART PLAYER ------------------------------------------------------------------------------------

SmartPlayer::SmartPlayer(std::string name)
:Player(name) {
    
}

bool SmartPlayer::isInteractive() const{
    return false;
}

// lets have south be negative for best, north be positive for best

//
// does not need isInteractive since it is in the virtual
int SmartPlayer::chooseMove(const Board& b, Side s) const {

//    int max = -20000;
//    int min = 20000;
//    int move = 0;
    Timer t;
    t.start();
    int best_hole = -1;
    int value = 0;
//=======================================================================================================
//    Board temp_board = b;
//    for(int i = 1; i <= b.holes(); i++){
//        if(s == NORTH){
//            // this sould be max
//            int new_max = minimax(temp_board, NORTH, true, 6);
//            if(new_max > max){
//                max = new_max;
//                move = i;
//            }
//        }
//        if(s == SOUTH){
//            int new_min = minimax(temp_board, SOUTH, false, 6);
//            if(new_min < min){
//                min = new_min;
//                move = i;
//            }
//        }
//    }
//=======================================================================================================
    minimax(b, s, best_hole, value, 4, 4, t);
    if(best_hole <= 0 || b.beans(s, best_hole) == 0){
        for(int i = 1; i <= b.holes(); i++){
            if(b.beans(s, i) != 0){
                best_hole = i;
                break;
            }
        }
    }
    return best_hole;
}

// is_max_player == true == NORTH
int SmartPlayer::minimax(const Board &b, Side s, int &best_hole, int &value, const int depth, int original_depth, Timer t) const{
    int endHole = 0;
    int h2 = 0;
    value = -10001;
    int v2 = -10000;
    Side endSide;
    if(b.beansInPlay(s) == 0){
        // if there are no beans on the side
        best_hole = -1;
        value = eval(b, s);
        return best_hole;
    }
    if(depth <= 0 || t.elapsed() > 4800
       
       ){
        // the depth is at the end or time is end
        best_hole = -1;
        value = eval(b, s);
        return best_hole;
    }
    for(int h = 1; h <= b.holes(); h++){
        if(b.beans(s, h) != 0){
            // make a temp board so the orginal board is not changed
            Board temp = b;
            // make the move on the temp board
            endHole = sow_and_capture(temp, s, h, endSide);
            
            if(endHole == 0){
                // the player can go again
                minimax(temp, s, h2, v2, depth, original_depth, t);
            } else{
                // the turn changes
                minimax(temp, opponent(s), h2, v2, depth - 1, original_depth, t);
            }
            // this assigning the hole and value at the top level
            if(original_depth % 2 == 0){
                if(v2 >= value){
                    value = v2;
                    if(depth == original_depth)
                        best_hole = h;
                }
            } else{
                if(v2 <= value){
                    value = v2;
                    if(depth == original_depth)
                        best_hole = h;
                }
            }
        }
    }
    
    return value;
    
//=======================================================================================================
//    Side end_side;
//    int best = 0;
//    bool isMax = is_max_player;
//    if(depth == 0){
//        return eval(b);
//    }
//    if(isMax == true){
//        best = -20000;
//        int max = -10000;
//        for(int i = 1; i <= b.holes(); i++){
//            Board temp_board = b;
//            if(b.beans(s, i) > 0){
//                int sowed = sow_and_capture(temp_board, s, i, end_side);
//                // if sowed = 0 not possible
//                // if sowed = 1 repeat turn
//                // if sowed = 2 change turn
//                if(sowed == 1){
//                    max = minimax(temp_board, s, isMax, depth - 1);
//                }
//                if(sowed == 2){
//                    isMax = false;
//                    max = minimax(temp_board, opponent(s), isMax, depth - 1);
//                }
//            }
//            if(best < max){
//                best = max;
//            }
//        }
//    }
//    if(isMax == false){
//        best = 20000;
//        int min = 20000;
//        for(int i = 1; i <= b.holes(); i++){
//            Board temp_board = b;
//            if(b.beans(s, i) > 0){
//                int sowed = sow_and_capture(temp_board, s, i, end_side);
//                if(sowed == 1){
//                    min = minimax(temp_board, s, isMax, depth - 1);
//                }
//                if(sowed == 2){
//                    isMax = true;
//                    min = minimax(temp_board, opponent(s), isMax, depth - 1);
//                }
//            }
//            if(best > min){
//                best = min;
//            }
//        }
//    }
//    return best;
//=======================================================================================================
    
}

// returns the end hole
// make a sow that has capture functionality, only change the max_player when the turn changes
int SmartPlayer::sow_and_capture(Board &b, Side s, int hole, Side &endSide) const{
    Side end_side;
    int end_hole;
    if(b.sow(s, hole, end_side, end_hole)){
        // a sow did happen
        if(end_hole == 0){
            // go again
            return 0;
        } else {
            if(b.beans(s, end_hole) == 1 && end_side == s && b.beans(opponent(s), end_hole) != 0 && end_hole != 0){
                // capturing
                b.moveToPot(opponent(s), end_hole, s);
                b.moveToPot(s, end_hole, s);
            }
            return end_hole;
        }
    }
    return -1;
}


int SmartPlayer::eval(Board b, Side s) const{
    // hueristic. beans in opponent is less than what we have and the game is over
    if(b.beans(s, 0) >= b.beans(opponent(s), 0) && (b.beansInPlay(NORTH) + b.beansInPlay(SOUTH) == 0)){
        return 5000;
    }
    if(b.beans(s, 0) <= b.beans(opponent(s), 0) && (b.beansInPlay(NORTH) + b.beansInPlay(SOUTH) == 0)){
        return -5000;
    }
    if(s == NORTH){
        return (b.beans(NORTH, 0) - b.beans(SOUTH, 0));
    } else{
        return (b.beans(SOUTH, 0) - b.beans(NORTH, 0));
    }

}

SmartPlayer::~SmartPlayer(){

}



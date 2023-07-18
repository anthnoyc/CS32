//
//  main.cpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#include <iostream>
#include <cassert>
#include "Board.h"
#include "Player.h"
#include "Game.h"
using namespace std;

void testgamme(){
    Board basd(6, 4);
    HumanPlayer p100("p1");
    BadPlayer p200("p2");
    Game g(basd, &p100, &p200);
    g.play();
}
int main() {
    

// BOARD TEST FUNCTIONS

    Side endside;
    int endhole;
    // there is no capturing in the board class
    Board b1(3, 0);
    assert(b1.beansInPlay(NORTH) == 0);
    assert(b1.beans(NORTH, 2) == 0);
    assert(b1.sow(NORTH, 2, endside, endhole ) == false);

    Board b2(5, 3);
    assert(b2.beansInPlay(NORTH) == 15);
    assert(b2.beansInPlay(SOUTH) == 15);
    assert(b2.beans(NORTH, 2) == 3);
    assert(b2.sow(NORTH, 3, endside, endhole) == true);
    assert(endside == NORTH && endhole == 0);

    // the capture functions work
    assert(b2.moveToPot(NORTH, 2, SOUTH) == true);
    assert(b2.beans(SOUTH, 0) == 4);
    assert(b2.totalBeans() == 30);

    // testing board constructor
    Board board3(-2, -3);
    assert(board3.holes() == 1);
    assert(board3.beans(NORTH, 1) == 0);
    assert(board3.beans(SOUTH, -1) == -1);

    // testing the beans function
    Board board4(6, 4);
    assert(board4.beans(NORTH, 7) == -1);
    assert(board4.beans(SOUTH, 0) == 0);
    assert(board4.beans(SOUTH, -2) == -1);

    // testing beans in play and totalbeans
    Board board5(4, 3);
    assert(board5.beansInPlay(NORTH) == 12);
    assert(board5.beansInPlay(SOUTH) == 12);
    assert(board5.beansInPlay(Side(5)) == -1);
    assert(board5.totalBeans() == 24);

    // testing sow
    Side endSide;
    int endHole;
    assert(!board5.sow(Side(3), 2, endSide, endHole));
    assert(!board5.sow(NORTH, 5, endSide, endHole));
    assert(!board5.sow(SOUTH, -1, endSide, endHole));
    assert(board5.sow(NORTH, 1, endSide, endHole));
    assert(endSide == SOUTH && endHole == 2);

    // testing movetopot
    Board board6(3, 2);
    assert(!board6.moveToPot(NORTH, 0, NORTH));
    assert(!board6.moveToPot(NORTH, 4, NORTH));
    assert(!board6.moveToPot(Side(2), 2, NORTH));
//
//// HUMAN PLAYER
//
//    HumanPlayer p1("p");
//    assert(p1.name() == "p");
//
////
//
//
//
//
//
//
//
//
//
       BadPlayer bp1("bad 1");
       BadPlayer bp2("bad 2");
       Board f(3, 0);
       f.setBeans(SOUTH, 1, 2);
       f.setBeans(NORTH, 2, 1);
       f.setBeans(NORTH, 3, 2);
       Game g(f, &bp1, &bp2);
       bool over;
       bool hasWinner;
       Side winner;
       g.status(over, hasWinner, winner);
       assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
              g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 2 &&
              g.beans(SOUTH, 1) == 2 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);

       g.move(SOUTH);
       g.status(over, hasWinner, winner);
       assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
              g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 0 &&
              g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
       g.move(NORTH);
       g.status(over, hasWinner, winner);
       assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
              g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
              g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
       g.move(SOUTH);
       g.status(over, hasWinner, winner);
       assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
              g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
              g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 1);
       g.move(NORTH);

//
//       Board alpha(1, 1);
//       alpha.setBeans(NORTH, 0, 9);
//       alpha.setBeans(NORTH, 1, 2);
//       alpha.setBeans(SOUTH, 1, 0);
//       alpha.setBeans(SOUTH, 0, 10);
//
//       BadPlayer cert("billy");
//       BadPlayer dad("jef");
//       Game beta(alpha, &cert, &dad);
//
//       bool ov = false;
//       bool haW = false;
//       Side wen = SOUTH;
//       beta.status(ov, haW, wen);
//       assert(ov && haW && wen == NORTH);
//       alpha.setBeans(NORTH, 1, 1);
//       Game gamma(alpha, &cert, &dad);
//       gamma.status(ov, haW, wen);
//       assert(ov && !haW);
//
//       cout << "game -- all passed\n";
//    cout << endl;
    
    
    
    Side end_side;
    int best_hole;
    int value;
    Timer t;
    t.start();
    Board b555(6, 4);

BadPlayer b("bad");
    HumanPlayer h("human");
// cout <<s.minimax(b555, SOUTH, best_hole, value, 3, 3, t);
    
    
    
    
//    cout << s.sow_and_capture(b555, NORTH, 2, end_side);
//    assert(s.eval(b555) == 1);

//    s.sow_and_capture(b555, NORTH, 1, end_side);
    // cout << s.eval(b555, NORTH);
//    cout << s.minimax(b555, NORTH, best_hole, value, 2, 2, t);
//    cout << best_hole;

    SmartPlayer p("smart");
    Game g1(b555, &p, &b);
    //g1.display();
    g1.play();
    
    

    
    cout << "pass" << endl;

}

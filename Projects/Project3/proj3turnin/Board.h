//
//  Board.hpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <vector>
#include "Side.h"

class Board{
public:
    Board(int nHoles, int nInitialBeansPerHole);
    Board(const Board &other);
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int &endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);
    
private:
    int m_holes;
    int m_initialBeans;
    std::vector<int> m_north;
    std::vector<int> m_south;
    
    
    
};

#endif /* Board_hpp */

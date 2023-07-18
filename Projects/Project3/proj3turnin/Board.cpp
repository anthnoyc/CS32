//
//  Board.cpp
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#include "Board.h"

Board::Board(int nHoles, int nInitialBeansPerHole){
    if(nHoles < 0){
        m_holes = 1;
    } else {
        m_holes = nHoles;
    }
    if(nInitialBeansPerHole < 0){
        m_initialBeans = 0;
    } else {
        m_initialBeans = nInitialBeansPerHole;
    }
    // number of holes per side
    // initialize the hole, which exists at index 0
    m_north.push_back(0);
    m_south.push_back(0);
    for(int i = 1; i <= m_holes; i ++){
        m_north.push_back(m_initialBeans);
        m_south.push_back(m_initialBeans);
    }
}

// MAYBE WILL NEED COPY CONSTRUCTOR
Board::Board(const Board &other)
:m_north(other.m_north), m_south(other.m_south)
{
    m_holes = other.m_holes;
    m_initialBeans = other.m_initialBeans;
    
}



int Board::holes() const{
    return m_holes;
}

int Board::beans(Side s, int hole) const{
    if((s != NORTH && s != SOUTH) || hole > m_holes || hole < 0){
        return -1;
    }
    if(s == NORTH){
        //return at hole because we start from 0 for pot, so first real hole is at 1
        return m_north.at(hole);
    } else if(s == SOUTH){
        return m_south.at(hole);
    }
    return 0;
}

int Board::beansInPlay(Side s) const{
    int total = 0;
    // checking for valid sides
    if(s != NORTH && s != SOUTH){
        return -1;
    }
    if(s == NORTH){
        // count total on north / south
        for(int i = 1; i < m_north.size(); i++){
            total += m_north[i];
        }
    } else {
        for(int i = 1; i < m_south.size(); i++){
            total += m_south[i];
        }
    }
    return total;
}

int Board::totalBeans() const{
    // count the total amount of beans using the other functions
    int total = 0;
    total += beansInPlay(NORTH);
    total += beansInPlay(SOUTH);
    // have to add the values for the pots
    total += m_north[0];
    total += m_south[0];
    return total;
}

bool Board::sow(Side s, int hole, Side& endSide, int &endHole){
    // the hole cannot be the pot, so hole cannot be = 0
    if(hole > m_holes || hole <= 0 || (s != NORTH && s != SOUTH)){
        return false;
    }
    int count = 0;
    if(s == NORTH){
        count = m_north.at(hole);
        if(count == 0){
            return false;
        }
        // set value inside hole = 0
        m_north[hole] = 0;
        int start_north = hole - 1;
        // to keep alternating between north and south
        while(count != 0){
            // for holes that come after selected hole
            for(int i = start_north; i >= 0; i--){
                // increase bean count by 1
                m_north[i]++;
                count --;
                if(count == 0){
                    // if no more beans to go around break
                    endSide = NORTH;
                    endHole = i;
                    return true;
                }

            }
            // reset the start position if we have to go again
            start_north = m_holes;
            // finished placing beans in the north side
            for(int i = 1; i < m_south.size(); i++){
                // south side starts from 0 and indexes up pot is at position 0
                m_south[i]++;
                count --;
                if(count == 0){
                    endSide = SOUTH;
                    endHole = i;
                    return true;
                }
            }
        }
        return true;
    } else if (s == SOUTH){
        count = m_south.at(hole);
        if(count == 0){
            return false;
        }
        m_south[hole] = 0;
        int start_south = hole + 1;
        while(count != 0){
            // this is looping through but not adding to the south pot
            for(int i = start_south; i < m_south.size(); i++){
                // south side starts from 0 and indexes up pot is at position 0
                m_south[i]++;
                count--;
                if(count == 0){
                    endSide = SOUTH;
                    endHole = i;
                    return true;
                }
            }
            start_south = 1;
            if(count != 0){
                m_south[0]++;
                count--;
            }
            //return if there are no more beans
            if(count == 0){
                endSide = SOUTH;
                endHole = 0;
                return true;
            }
            //loop negative indexing through the north side, avoiding the pot
            for(int i = m_north.size() - 1; i >= 1; i--){
                m_north[i]++;
                count--;
                if(count == 0){
                    endSide = NORTH;
                    endHole = i;
                    return true;
                }
            }
            
        }
        return true;
    }
    return false; // TO DO
}


// this functionality will be used for capturing
bool Board::moveToPot(Side s, int hole, Side potOwner){
    if((s != NORTH && s != SOUTH) || hole <= 0 || hole > m_holes){
        return false;
    }
    int amount;
    if(s == NORTH){
        // extract from north hole
        amount = m_north.at(hole);
        m_north.at(hole) = 0;
    } else {
        amount = m_south.at(hole);
        m_south.at(hole) = 0;
    }
    if(potOwner == NORTH){
        m_north.at(0) += amount;
    }
    if(potOwner == SOUTH){
        m_south.at(0) += amount;
    }
    return true;
}


bool Board::setBeans(Side s, int hole, int beans){
    if((s != NORTH && s != SOUTH) || hole < 0 || hole > m_holes || beans < 0){
        return false;
    }
    if(s == NORTH){
        m_north.at(hole) = beans;
    }
    if(s == SOUTH){
        m_south.at(hole) = beans;
    }
    
    return true;
}


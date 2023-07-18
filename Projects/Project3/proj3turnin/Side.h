//
//  Sid.h
//  Project3
//
//  Created by Anthony Chen on 5/20/23.
//

#ifndef Sid_h
#define Sid_h
#include <stdio.h>
enum Side { NORTH, SOUTH };

const int NSIDES = 2;
const int POT = 0;

inline
Side opponent(Side s)
{
    return Side(NSIDES - 1 - s);
}

#endif /* Sid_h */

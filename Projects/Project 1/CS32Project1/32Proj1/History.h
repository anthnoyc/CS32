//
//  History.hpp
//  32Proj1
//
//  Created by Anthony Chen on 4/8/23.
//

#ifndef History_hpp
#define History_hpp
#include <stdio.h>
#include "globals.h"

class History {
private:
    int m_rows;
    int m_cols;
    int m_display[MAXROWS][MAXCOLS];
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
};
#endif /* History_hpp */

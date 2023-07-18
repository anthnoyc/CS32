//
//  History.cpp
//  32Proj1
//
//  Created by Anthony Chen on 4/8/23.
//

#include "History.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    
    for(int i = 0; i < m_rows; i++){
        for(int j = 0; j < m_cols; j++){
            m_display[i][j] = 0;
        }
    }
};

bool History::record(int r, int c){
    if(r >= 1 && r <= m_rows && c >= 1 && c <= m_cols){
        m_display[r-1][c-1]++;
        return true;
    } else {
        return false;
    }
    
}

void History::display() const{
    clearScreen();
    
    for(int r = 0; r < m_rows; r++){
        for (int c = 0; c < m_cols; c++){
            int entry = m_display[r][c];
            if(entry == 0){
                cout << '.';
            } else if (entry >= 26) {
                cout << 'Z';
            } else
                cout << char('A' + m_display[r][c] - 1);
        }
        cout << endl;
    }
    cout << endl;
}

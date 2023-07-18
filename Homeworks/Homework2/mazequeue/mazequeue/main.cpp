//
//  main.cpp
//  Homework2
//
//  Created by Anthony Chen on 4/28/23.
//

#include <iostream>
#include <queue>

using namespace std;

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);
          // Return true if there is a path from (sr,sc) to (er,ec)
          // through the maze; return false otherwise

class Coord
{
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    queue <Coord> coordStack;
    Coord curr(0, 0);
    coordStack.push(Coord(sr, sc));
    maze[sr][sc] = '0';
    while(!coordStack.empty()){
        curr = coordStack.front();
        coordStack.pop();
        if(curr.r() == er && curr.c() == ec){
            return true;
        }
        if(maze[curr.r() + 1][curr.c()] =='.' ){
            // can move south
            coordStack.push(Coord(curr.r() + 1, curr.c()));
            maze[curr.r() + 1][curr.c()] = '0';
        }
        if(maze[curr.r()][curr.c() + 1] =='.' ){
            // can move east
            coordStack.push(Coord(curr.r(), curr.c() + 1));
            maze[curr.r()][curr.c() + 1] = '0';
        }
        if(maze[curr.r() - 1][curr.c()] =='.' ){
            // can move north
            coordStack.push(Coord(curr.r() - 1, curr.c()));
            maze[curr.r() - 1][curr.c()] = '0';
        }
        if(maze[curr.r()][curr.c() - 1] =='.' ){
            // can move west
            coordStack.push(Coord(curr.r(), curr.c() - 1));
            maze[curr.r()][curr.c() - 1] = '0';
        }
    }
    return false;
}

int main() {
            
                char maze[10][10] = {
                    { 'X','X','X','X','X','X','X','X','X','X' },
                    { 'X','.','.','.','X','.','.','.','.','X' },
                    { 'X','.','.','X','X','.','X','X','.','X' },
                    { 'X','.','X','.','.','.','.','X','X','X' },
                    { 'X','X','X','X','.','X','X','X','.','X' },
                    { 'X','.','.','X','.','.','.','X','.','X' },
                    { 'X','.','.','X','.','X','.','.','.','X' },
                    { 'X','X','.','X','.','X','X','X','X','X' },
                    { 'X','.','.','.','.','.','.','.','.','X' },
                    { 'X','X','X','X','X','X','X','X','X','X' }
                };

                if (pathExists(maze, 3,4, 8,1))
                    cout << "Solvable!" << endl;
                else
                    cout << "Out of luck!" << endl;
            
    return 0;
}

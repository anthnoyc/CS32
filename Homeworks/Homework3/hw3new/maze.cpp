//
//  main.cpp
//  Homework2
//
//  Created by Anthony Chen on 4/28/23.
//

//#include <iostream>

//using namespace std;

bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    if(sr == er && sc == ec){
        return true;
    }
    maze[sr][sc] = 'O';
    bool result;
    if(maze[sr][sc + 1] == '.'){
        // can move EAST
        result = pathExists(maze, sr, sc + 1, er, er);
        if(result){
            return true;
        }
    }
    if(maze[sr + 1][sc] == '.'){
        // can move SOUTH
        result = pathExists(maze, sr + 1, sc, er, er);
        if(result){
            return true;
        }
    }
    if(maze[sr][sc - 1] == '.'){
        // can move WEST
        result = pathExists(maze, sr, sc - 1, er, er);
        if(result){
            return true;
        }
    }
    if(maze[sr - 1][sc] == '.'){
        // can move NORTH
        result = pathExists(maze, sr - 1, sc, er, er);
        if(result){
            return true;
        }
    }
    return false;
}


//int main() {
//
//                char maze[10][10] = {
//                    { 'X','X','X','X','X','X','X','X','X','X' },
//                    { 'X','.','.','.','X','.','.','.','.','X' },
//                    { 'X','.','.','X','X','.','X','X','.','X' },
//                    { 'X','.','X','.','.','.','.','X','X','X' },
//                    { 'X','X','X','X','.','X','X','X','.','X' },
//                    { 'X','.','.','X','.','.','.','X','.','X' },
//                    { 'X','.','.','X','.','X','.','.','.','X' },
//                    { 'X','X','.','X','.','X','X','X','X','X' },
//                    { 'X','.','.','.','.','.','.','.','.','X' },
//                    { 'X','X','X','X','X','X','X','X','X','X' }
//                };
//
//                if (pathExists(maze, 3,4, 8,1))
//                    cout << "Solvable!" << endl;
//                else
//                    cout << "Out of luck!" << endl;
//
//    return 0;
//}

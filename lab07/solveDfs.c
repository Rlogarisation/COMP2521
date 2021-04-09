// DFS maze solver

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cell.h"
#include "helpers.h"
#include "Maze.h"
#include "Stack.h"

bool solve(Maze m) {
    bool found = false;
    // Initiate a visited stack to store 
    // the visiting order for dfs algo
    Stack s = StackNew();
    // Initiate a 2d array to store 
    // the last vertex to this vertex
    Cell **visited = createCellMatrix(MazeHeight(m), MazeWidth(m));
    Cell src = MazeGetStart(m);
    Cell des;
    // Mark the starting point as visited.
    StackPush(s, src);
    visited[src.row][src.col] = src;

    while (found == false && StackIsEmpty(s) == false) {
        Item v = StackPop(s);
        if (MazeIsWall(m, v) == false && 
        MazeVisit(m, v) == true) {
            found = true;
            des = v;
        }
        else {
            // Find path then stackpush
            // If v is not wall,
            // v is not visited
            Cell left = v;
            left.col = v.col - 1;
            if (left.col >= 0 && MazeIsWall(m, left) == false && 
            visited[left.row][left.col].row == 0 && 
            visited[left.row][left.col].col == 0) {
                visited[left.row][left.col] = v;
                StackPush(s, left);
            }
            Cell right = v;
            right.col = v.col + 1;
            if (right.col <= MazeWidth(m) && 
            MazeIsWall(m, right) == false && 
            visited[right.row][right.col].row == 0 && 
            visited[right.row][right.col].col == 0) {
                visited[right.row][right.col] = v;
                StackPush(s, right);
            }
            Cell up = v;
            up.row = v.row - 1;
            if (up.row >= 0 && MazeIsWall(m, up) == false && 
            visited[up.row][up.col].row == 0 && 
            visited[up.row][up.col].col == 0) {
                visited[up.row][up.col] = v;
                StackPush(s, up);
            }
            Cell down = v;
            down.row = v.row + 1;
            if (down.row <= MazeHeight(m) && 
            MazeIsWall(m, down) == false &&  
            visited[down.row][down.col].row == 0 && 
            visited[down.row][down.col].col == 0) {
                visited[down.row][down.col] = v;
                StackPush(s, down);
            }
        }
    }
    if (found == true) {
        Cell temp = des;
        while (temp.row != src.row || temp.col != src.col) {
            MazeMarkPath(m, temp);
            temp = visited[temp.row][temp.col];
        }
        MazeMarkPath(m, temp);
        MazeMarkPath(m, src);
        return true;
    }
    
    freeCellMatrix(visited);
    return false;
}


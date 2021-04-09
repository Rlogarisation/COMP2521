// Recursive DFS maze solver with backtracking

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cell.h"
#include "helpers.h"
#include "Maze.h"
bool solve(Maze m) {
    return false;
}

/*
bool dfsPathCheck(Maze m, Cell v, Cell **visited, Cell src);

bool solve(Maze m) {
    // Initiate a 2d array to store 
    // the last vertex to this vertex
    
    Cell **visited = createCellMatrix(MazeHeight(m), MazeWidth(m));
    Cell src = MazeGetStart(m);
    // Mark the starting point as visited.
    visited[src.row][src.col] = src;
    
    return dfsPathCheck(m, src, visited, src);

    freeCellMatrix(visited);
    
}

bool dfsPathCheck(Maze m, Cell v, Cell **visited, Cell src) {
    // Find path then stackpush
    // If v is not wall,
    // v is not visited
    Cell left = v;
    left.col = v.col - 1;
    if (left.col >= 0 && MazeIsWall(m, left) == false && 
    visited[left.row][left.col].row == 0 && 
    visited[left.row][left.col].col == 0) {
        visited[left.row][left.col] = v;
        if (MazeIsWall(m, left) == false && 
        MazeVisit(m, left) == true) {
            MazeMarkPath(m, left);
            return true;
        }
        else if (dfsPathCheck(m, left, visited, src) == true) {
            MazeMarkPath(m, left);
            return true;
        }
    }
    Cell right = v;
    right.col = v.col + 1;
    if (right.col <= MazeWidth(m) && 
    MazeIsWall(m, right) == false && 
    visited[right.row][right.col].row == 0 && 
    visited[right.row][right.col].col == 0) {
        visited[right.row][right.col] = v;
        if (MazeIsWall(m, right) == false && 
        MazeVisit(m, right) == true) {
            MazeMarkPath(m, right);
            return true;
        }
        else if (dfsPathCheck(m, right, visited, src) == true) {
            MazeMarkPath(m, right);
            return true;
        }
    }
    Cell up = v;
    up.row = v.row - 1;
    if (up.row >= 0 && MazeIsWall(m, up) == false && 
    visited[up.row][up.col].row == 0 && 
    visited[up.row][up.col].col == 0) {
        visited[up.row][up.col] = v;
        if (MazeIsWall(m, up) == false && 
        MazeVisit(m, up) == true) {
            MazeMarkPath(m, up);
            return true;
        }
        else if (dfsPathCheck(m, up, visited, src) == true) {
            MazeMarkPath(m, up);
            return true;
        }
    }
    Cell down = v;
    down.row = v.row + 1;
    if (down.row <= MazeHeight(m) && 
    MazeIsWall(m, down) == false &&  
    visited[down.row][down.col].row == 0 && 
    visited[down.row][down.col].col == 0) {
        visited[down.row][down.col] = v;
        if (MazeIsWall(m, down) == false && 
        MazeVisit(m, down) == true) {
            MazeMarkPath(m, down);
            return true;
        }
        else if (dfsPathCheck(m, down, visited, src) == true) {
            MazeMarkPath(m, down);
            return true;
        }
    }
    return false;

}
*/
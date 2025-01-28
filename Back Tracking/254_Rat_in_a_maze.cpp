/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It 
has to reach the destination at (N - 1, N - 1). Find all possible paths 
that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 
'L' (left), 'R' (right). Value 0 at a cell in the matrix represents 
that it is blocked and rat cannot move to it while value 1 at a cell in 
the matrix represents that rat can be travel through it.

Note: In a path, no cell can be visited more than one time. If the 
source cell is 0, the rat cannot move to any other cell.

Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Link : https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030
Example 1:
    Input:
    N = 4
    m[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1}, 
            {1, 1, 0, 0},
            {0, 1, 1, 1}}

    Output:
    DDRDRR DRDDRR

    Explanation:
    The rat can reach the destination at (3, 3) from (0, 0) by two 
    paths - DRDDRR and DDRDRR, when printed in sorted order we get 
    DDRDRR DRDDRR.

Example 2:
    Input:
    N = 2
    m[][] = {{1, 0},
            {1, 0}}

    Output:
    -1

    Explanation:
    No path exists and destination cell is blocked.


Constraints:
    2 ≤ N ≤ 5
    0 ≤ m[i][j] ≤ 1

    Expected Time Complexity: O((3N^2)).
    Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int new_x, int new_y, vector<vector<bool>> &visited,
           vector<vector<int> > &maze, int n){
    if((new_x >= 0 && new_x < n) && (new_y >=0 && new_y < n) 
       && visited[new_x][new_y] != 1 && maze[new_x][new_y] == 1){
        return true;
    }else{
        return false;
    }
}

void solve(int x, int y, vector<vector<int> > &maze, int n, vector<string> &ans, 
          vector<vector<bool>> &visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    
    if(isSafe(x+1, y, visited, maze, n)){
        solve(x+1, y, maze, n, ans, visited, path+'D');
    }
    if(isSafe(x, y-1, visited, maze, n)){
        solve(x, y-1, maze, n, ans, visited, path+'L');
    }
    if(isSafe(x, y+1, visited, maze, n)){
        solve(x, y+1, maze, n, ans, visited, path+'R');
    }
    if(isSafe(x-1, y, visited, maze, n)){
        solve(x-1, y, maze, n, ans, visited, path+'U');
    }
    
    visited[x][y] = 0;
}

vector <string> searchMaze(vector < vector < int >> & maze, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool> (n, 0));
    string path = "";
    
    if(maze[0][0] == 0){
        return ans;
    }
    solve(0, 0, maze, n, ans, visited, path);
    return ans;
}
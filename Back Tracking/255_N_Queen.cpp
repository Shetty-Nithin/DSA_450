/*
The n-queens puzzle is the problem of placing n queens on a (n×n) 
chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. 
Each solution contains distinct board configurations of the n-queens’ 
placement, where the solutions are a permutation of [1,2,3..n] in 
increasing order, here the number in the ith place denotes that the 
ith-column queen is placed in the row with that number. For eg below 
figure represents a chessboard [3 1 4 2].

Link : https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1/
Link : https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286

Example 1:
    Input:
    1

    Output:
    [1]

    Explaination:
    Only one queen can be placed in the single cell available.

Example 2:
    Input:
    4

    Output:
    [2 4 1 3 ] [3 1 4 2 ]

    Explaination:
    These are the 2 possible solutions.

Constraints:
    1 ≤ n ≤ 10 

    Expected Time Complexity: O(n!)
    Expected Auxiliary Space: O(n2) 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;
    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    
    x = row;
    y = col;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    x = row;
    y = col;
    while(x < n && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    if(col == n){
        addSolution(ans, board, n);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    
    solve(0, ans, board, n);
    return ans;
}
/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square 
matrix (grid[][]), the task to find a solved Sudoku. For simplicity, 
you may assume that there will be only one unique solution.

Link : https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
Link : https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919

Example 1:
    Input:
    grid[][] = 
    [[3 0 6 5 0 8 4 0 0],
     [5 2 0 0 0 0 0 0 0],
     [0 8 7 0 0 0 0 3 1],
     [0 0 3 0 1 0 0 8 0],
     [9 0 0 8 6 3 0 0 5],
     [0 5 0 0 9 0 6 0 0],
     [1 3 0 0 0 0 2 5 0],
     [0 0 0 0 0 0 0 7 4],
     [0 0 5 2 0 6 3 0 0]]

    Output:
    3 1 6 5 7 8 4 9 2
    5 2 9 1 3 4 7 6 8
    4 8 7 6 2 9 5 3 1
    2 6 3 4 1 5 9 8 7
    9 7 4 8 6 3 1 2 5
    8 5 1 7 9 2 6 4 3
    1 3 8 9 4 7 2 5 6
    6 9 2 3 5 1 8 7 4
    7 4 5 2 8 6 3 1 9



Constraints:
    0 ≤ grid[i][j] ≤ 9

    Expected Time Complexity: O(9N*N).
    Expected Auxiliary Space: O(N*N).
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isSafe(int row, int col, vector<vector<int>>& sudoku, int val){
    for(int i=0; i<sudoku.size(); i++){
        if(sudoku[row][i] == val || sudoku[i][col] == val){
            return false;
        }
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku){
    int n = sudoku[0].size();
    
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(sudoku[row][col] == 0){
                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, sudoku,val)){
                        sudoku[row][col] = val;
                        
                        bool sudokuCompleted = solve(sudoku);
                        if(sudokuCompleted == true){
                            return true;
                        }else{
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;    
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
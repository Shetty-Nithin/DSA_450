/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Link : https://leetcode.com/problems/maximal-square/description/
Link : https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0

Example 1: 
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 4

Example 2:
    Input: matrix = [["0","1"],["1","0"]]
    Output: 1

Example 3:
    Input: matrix = [["0"]]
    Output: 0

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 300
    matrix[i][j] is '0' or '1'.
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int maximalSquareUtil(vector<vector<char>>& matrix, int row, int col, int& maxi){
        if(row >= matrix.size() || col >= matrix[0].size()){
            return 0;
        }

        int right = maximalSquareUtil(matrix, row, col+1, maxi);
        int diagonal = maximalSquareUtil(matrix, row+1, col+1, maxi);
        int down = maximalSquareUtil(matrix, row+1, col, maxi);

        if(matrix[row][col] == '1'){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }else{
            return 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        maximalSquareUtil(matrix, 0, 0, maxi);
        return maxi*maxi;
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int maximalSquareUtil(vector<vector<char>>& matrix, int row, int col, int& maxi, vector<vector<int>>& dp){
        if(row >= matrix.size() || col >= matrix[0].size()){
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int right = maximalSquareUtil(matrix, row, col+1, maxi, dp);
        int diagonal = maximalSquareUtil(matrix, row+1, col+1, maxi,dp);
        int down = maximalSquareUtil(matrix, row+1, col, maxi, dp);

        if(matrix[row][col] == '1'){
            dp[row][col] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[row][col]);
            return dp[row][col];
        }else{
            return dp[row][col] = 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        maximalSquareUtil(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // +1 to avoid out of bound

        for(int row=n-1; row>=0; row--){
            for(int col=m-1; col>=0; col--){
                int right = dp[row][col+1];
                int diagonal = dp[row+1][col+1];
                int down = dp[row+1][col];

                if(matrix[row][col] == '1'){
                    dp[row][col] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[row][col]);
                }else{
                    dp[row][col] = 0;
                }
            }
        }

        return maxi*maxi;
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for(int row=n-1; row>=0; row--){
            for(int col=m-1; col>=0; col--){
                int right = curr[col+1];
                int diagonal = next[col+1];
                int down = next[col];

                if(matrix[row][col] == '1'){
                    curr[col] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[col]);
                }else{
                    curr[col] = 0;
                }
            }
            next = curr;
        }

        return maxi*maxi;
    }
};
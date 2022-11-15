/*
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is
the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares
while 3 and 11 are not.
Link : https://leetcode.com/problems/perfect-squares/

Example 1:
    Input: n = 12
    Output: 3
    Explanation: 12 = 4 + 4 + 4.

Example 2:
    Input: n = 13
    Output: 2
    Explanation: 13 = 4 + 9.

Constraints:
    1 <= n <= 104
*/


#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int numSquaresUtil(int n){
        if(n == 0){
            return 0;
        }

        int ans = n;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, 1+numSquaresUtil(n-i*i));
        }

        return ans;
    }
public:
    int numSquares(int n) {
        return numSquaresUtil(n);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int numSquaresUtil(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = n;
        for(int i=1; i*i<=n; i++){
            dp[n] = min(dp[n], 1+numSquaresUtil(n-i*i, dp));
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return numSquaresUtil(n, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=n; j++){
                if((i-j*j) >= 0){
                    dp[i] = min(dp[i], 1+dp[i-j*j]);
                }
            }
        }

        return dp[n];
    }
};
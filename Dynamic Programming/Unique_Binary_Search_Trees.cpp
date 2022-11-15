/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes 
of unique values from 1 to n.
Link : https://leetcode.com/problems/unique-binary-search-trees/description/

Example 1:
    Input: n = 3
    Output: 5

Example 2:
    Input: n = 1
    Output: 1

Constraints:
    1 <= n <= 19
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += numTrees(i-1)*numTrees(n-i);
        }

        return ans;
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private: 
    int numTreesUtil(int n, vector<int>& dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += numTreesUtil(i-1, dp)*numTreesUtil(n-i, dp);
        }

        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return numTreesUtil(n, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for(int k=2; k<=n; k++){
            for(int i=1; i<=k; i++){
                dp[k] += dp[i-1]*dp[k-i];
            }
        }

        return dp[n];
    }
};

// Approach 4 : Using Catalan Series
/*
You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in front of you,
the ith basket is meant for the ith ball. Calculate the number of ways in which no ball goes into its respective basket.
Link : https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?page=1&category[]=Combinatorial&sortBy=submissions

Example 1:
    Input: N = 2
    Output: 1
    Explanation: The balls are numbered 1 and 2. 
    Then there is only one way to dearrange them. 
    The (number-basket) pairs will be [(1-2),(2-1)].

Example 2:
    Input: 3
    Output: 2
    Explanation: The (number-basket) pairs are 
    [(1-3),(2-1),(3-2)] and [(1-2),(2-3),(3-2)].

Constraints : 
    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
    1 ≤ N ≤ 104
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Approach 1 : Recurssion
class Solution{
public:
    long int disarrange(int N){
        if(N == 1) return 0;
        if(N == 2) return 1;
        
        return ((N-1)%MOD*(disarrange(N-2)%MOD + disarrange(N-1)%MOD))%MOD;
    }
};

// Approach 2 : Recurssion + Memoization
class Solution{
private: 
    long int disarrangeUtil(int N, vector<long int> &dp){
        if(N == 1) return 0;
        if(N == 2) return 1;
        
        if(dp[N] != -1) return dp[N];
        dp[N] = ( ((N-1)%MOD) *( (disarrangeUtil(N-2, dp)%MOD) + (disarrangeUtil(N-1, dp)%MOD))%MOD);
        return dp[N];
    }
public:
    long int disarrange(int N){
        vector<long int> dp(N+1, -1);
        return disarrangeUtil(N, dp);
    }
};

// Approach 3 : Bottoms-Up
class Solution{
public:
    long int disarrange(int N){
        vector<long int> dp(N+1, -1);
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i=3; i<=N; i++){
            dp[i] = ((i-1)% MOD) * ((dp[i-2]%MOD) + (dp[i-1]%MOD))%MOD;
        }
        
        return dp[N];
    }
};

// Approach 4 : Bottoms-Up with space optimization
class Solution{
public:
    long int disarrange(int N){
        vector<long int> dp(N+1, -1);
        long int prev2 = 0;
        long int prev1 = 1;
        
        for(int i=3; i<=N; i++){
            long int ans = ((i-1)% MOD) * ((prev1%MOD) + (prev2%MOD))%MOD;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};
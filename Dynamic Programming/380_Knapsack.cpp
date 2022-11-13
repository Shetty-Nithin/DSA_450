/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total
value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated
with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value
subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item,
either pick the complete item or dont pick it (0-1 property).
Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

Example 1:
    Input:
    N = 3
    W = 4
    values[] = {1,2,3}
    weight[] = {4,5,1}
    Output: 3

Example 2:
    Input:
    N = 3
    W = 3
    values[] = {1,2,3}
    weight[] = {4,5,6}
    Output: 0

Constraints:
    1 ≤ N ≤ 1000
    1 ≤ W ≤ 1000
    1 ≤ wt[i] ≤ 1000
    1 ≤ v[i] ≤ 1000
    Expected Time Complexity: O(N*W).
    Expected Auxiliary Space: O(N*W)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Approach 1 : Recurssion (TLE)
class Solution{
private:
    int solve(int capacity, int wt[], int val[], int index){
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            return 0;
        }
        
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index] + solve(capacity-wt[index], wt, val, index-1);
        }
        int excl = solve(capacity, wt, val, index-1);
        
        return max(incl, excl);
    }   
public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      return solve(W, wt, val, n-1);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution{
private:
    int solve(int capacity, int wt[], int val[], int index, vector<vector<int>> &dp){
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            return 0;
        }
        
        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index] + solve(capacity-wt[index], wt, val, index-1, dp);
        }
        int excl = solve(capacity, wt, val, index-1, dp);
        
        dp[index][capacity] = max(incl, excl);
        return dp[index][capacity];
    }   
public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(W, wt, val, n-1, dp);
    }
};


// Approach 3 : Bottom-Up/Tabulation
class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n){ 
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= W){
                dp[0][w] = val[0];
            }
            else dp[0][w] = 0;
        }
        
        for(int index=1; index<n; index++){
            for(int w=0; w<=W; w++){
                int incl = 0;
                if(wt[index] <= w){
                    incl = val[index] + dp[index-1][w-wt[index]];
                }
                int excl = dp[index-1][w];
                
                dp[index][w] = max(incl, excl);
            }
        }
        return dp[n-1][W];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimisation
class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n){ 
        vector<int> prev(W+1, 0);
        vector<int> curr(W+1, 0);
        
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= W){
                prev[w] = val[0];
            }
            else prev[w] = 0;
        }
        
        for(int index=1; index<n; index++){
            for(int w=0; w<=W; w++){
                int incl = 0;
                if(wt[index] <= w){
                    incl = val[index] + prev[w-wt[index]];
                }
                int excl = prev[w];
                
                curr[w] = max(incl, excl);
            }
            prev = curr;
        }
        return prev[W];
    }
};

// Approach 5 : Bottom-Up/Tabulation with space optimisation
class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n){ 
        vector<int> curr(W+1, 0);
        
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= W){
                curr[w] = val[0];
            }
            else curr[w] = 0;
        }
        
        for(int index=1; index<n; index++){
            for(int w=W; w>=0; w--){
                int incl = 0;
                if(wt[index] <= w){
                    incl = val[index] + curr[w-wt[index]];
                }
                int excl = curr[w];
                
                curr[w] = max(incl, excl);
            }
        }
        return curr[W];
    }
};
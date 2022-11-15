/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost,
you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
Link : https://leetcode.com/problems/min-cost-climbing-stairs/

Example 1:
    Input: cost = [10,15,20]
    Output: 15
    Explanation: You will start at index 1.
                 - Pay 15 and climb two steps to reach the top. The total cost is 15.

Example 2:
    Input: cost = [1,100,1,1,1,100,1,1,100,1]
    Output: 6
    Explanation: You will start at index 0.
    - Pay 1 and climb two steps to reach index 2.
    - Pay 1 and climb two steps to reach index 4.
    - Pay 1 and climb two steps to reach index 6.
    - Pay 1 and climb one step to reach index 7.
    - Pay 1 and climb two steps to reach index 9.
    - Pay 1 and climb one step to reach the top.
    The total cost is 6.

Constraints:
    2 <= cost.length <= 1000
    0 <= cost[i] <= 999
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach : Recurssion + Memoization
class Solution {
private:
    int minCostClimbingStairsUtil(int step, vector<int> &cost,int n, vector<int> &memo){
        if(step == n-1 || step == n-2){
            return cost[step];
        }
        if(memo[step] != -1){ // memoization
            return memo[step];
        }
        memo[step] = cost[step] + min(minCostClimbingStairsUtil(step+1, cost, n, memo), minCostClimbingStairsUtil(step+2, cost, n, memo));
        return memo[step];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);

        if(n <= 2){
            return min(cost[0], cost[1]);
        }
        return min(minCostClimbingStairsUtil(0, cost, n, memo), minCostClimbingStairsUtil(1, cost, n, memo));
    }
};
                                                                                                                                              
// Approach : Bottoms-Up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);

        if(n <= 2){
            return min(cost[0], cost[1]);
        }

        vector<int> minCostsTabulation(n, 0);
        minCostsTabulation[n-1] = cost[n-1];
        minCostsTabulation[n-2] = cost[n-2];
        for(int i=n-3; i>=0; i--){
            minCostsTabulation[i] = cost[i] + min(minCostsTabulation[i+1], minCostsTabulation[i+2]);
        }
        
        return min(minCostsTabulation[0], minCostsTabulation[1]);
    }
};

// Appraoch 3 : Space optimization by using varaible instead of vector.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);

        if(n <= 2){
            return min(cost[0], cost[1]);
        }

        int prev1 = cost[n-2];
        int prev2 = cost[n-1];
        for(int i=n-3; i>=0; i--){
            int ans = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = ans;
        }
        
        return min(prev1, prev2);
    }
};
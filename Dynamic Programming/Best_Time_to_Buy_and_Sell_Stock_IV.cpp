/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

Example 1:
    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and 
                sell on day 6 (price = 3), profit = 3-0 = 3.

Constraints:
    1 <= k <= 100
    1 <= prices.length <= 1000
    0 <= prices[i] <= 1000
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();        
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for(int index=n-1; index>=0; index--){
            for(int isBuyable=0; isBuyable<=1; isBuyable++){
                for(int limit=1; limit<=k; limit++){
                    int profit = 0;
                    if(isBuyable){
                        int buy = -prices[index] + next[0][limit];
                        int skip =  next[1][limit];
                        profit = max(buy, skip);
                    }
                    else{
                        int sell = prices[index] + next[1][limit-1];
                        int skip =  next[0][limit];
                        profit = max(sell, skip);
                    }
                    curr[isBuyable][limit] = profit;
                }
                next = curr;
            }
        }

        return curr[1][k]; 
    }
};


// Approach 1 : Recurssion
class Solution {
private: 
    int maxProfitUtil(int k, vector<int>& prices, int index, int operationNo){
        if(index == prices.size()){
            return 0;
        }
        if(operationNo == 2*k){
            return 0;
        }

        int profit = 0;
        if(operationNo%2 == 0){
            int buy = -prices[index] + maxProfitUtil(k, prices, index+1, operationNo+1);
            int skip =  maxProfitUtil(k, prices, index+1, operationNo);
            profit = max(buy, skip);
        }
        else {
            int sell = prices[index] + maxProfitUtil(k, prices, index+1, operationNo+1);
            int skip =  maxProfitUtil(k, prices, index+1, operationNo);
            profit = max(sell, skip);
        }
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return maxProfitUtil(k, prices, 0, 0);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private: 
    int maxProfitUtil(int k, vector<int>& prices, int index, int operationNo, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(operationNo == 2*k){
            return 0;
        }
        if(dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }

        int profit = 0;
        if(operationNo%2 == 0){
            int buy = -prices[index] + maxProfitUtil(k, prices, index+1, operationNo+1, dp);
            int skip =  maxProfitUtil(k, prices, index+1, operationNo, dp);
            profit = max(buy, skip);
        }
        else {
            int sell = prices[index] + maxProfitUtil(k, prices, index+1, operationNo+1, dp);
            int skip =  maxProfitUtil(k, prices, index+1, operationNo, dp);
            profit = max(sell, skip);
        }
        return dp[index][operationNo] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k, -1));
        return maxProfitUtil(k, prices, 0, 0, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int index=n-1; index>=0; index--){
            for(int operationNo=0; operationNo<2*k; operationNo++){
                int profit = 0;
                if(operationNo%2 == 0){
                    int buy = -prices[index] + dp[index+1][operationNo+1];
                    int skip =  dp[index+1][operationNo];
                    profit = max(buy, skip);
                }
                else {
                    int sell = prices[index] + dp[index+1][operationNo+1];
                    int skip =  dp[index+1][operationNo];
                    profit = max(sell, skip);
                }
                dp[index][operationNo] = profit;
            }
        }

        return dp[0][0];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();        
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for(int index=n-1; index>=0; index--){
            for(int operationNo=0; operationNo<2*k; operationNo++){
                int profit = 0;
                if(operationNo%2 == 0){
                    int buy = -prices[index] + next[operationNo+1];
                    int skip =  next[operationNo];
                    profit = max(buy, skip);
                }
                else {
                    int sell = prices[index] + next[operationNo+1];
                    int skip =  next[operationNo];
                    profit = max(sell, skip);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }

        return curr[0]; 
    }
};
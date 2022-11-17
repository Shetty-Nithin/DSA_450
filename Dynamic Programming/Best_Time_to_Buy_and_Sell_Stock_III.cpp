/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock
before you buy again).
Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
                 Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
                 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple
                 transactions at the same time. You must sell before buying again.

Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constraints:
    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^5
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int maxProfitUtil(vector<int>& prices, int isBuyable, int index, int limit){
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }

        int profit = 0;
        if(isBuyable){
            int buy = -prices[index] + maxProfitUtil(prices, 0, index+1, limit);
            int skip =  maxProfitUtil(prices, 1, index+1, limit);
            profit = max(buy, skip);
        }
        else{
            int sell = prices[index] + maxProfitUtil(prices, 1, index+1, limit-1);
            int skip =  maxProfitUtil(prices, 0, index+1, limit);
            profit = max(sell, skip);
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return maxProfitUtil(prices, 1, 0, 2); 
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int maxProfitUtil(vector<int>& prices, int isBuyable, int index, int limit, vector<vector<vector<int>>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }
        if(dp[index][isBuyable][limit] != -1){
            return dp[index][isBuyable][limit];
        }

        int profit = 0;
        if(isBuyable){
            int buy = -prices[index] + maxProfitUtil(prices, 0, index+1, limit, dp);
            int skip =  maxProfitUtil(prices, 1, index+1, limit, dp);
            profit = max(buy, skip);
        }
        else{
            int sell = prices[index] + maxProfitUtil(prices, 1, index+1, limit-1, dp);
            int skip =  maxProfitUtil(prices, 0, index+1, limit, dp);
            profit = max(sell, skip);
        }
        return dp[index][isBuyable][limit] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return maxProfitUtil(prices, 1, 0, 2, dp); 
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int index=n-1; index>=0; index--){
            for(int isBuyable=0; isBuyable<=1; isBuyable++){
                for(int limit=1; limit<=2; limit++){
                    int profit = 0;
                    if(isBuyable){
                        int buy = -prices[index] + dp[index+1][0][limit];
                        int skip =  dp[index+1][1][limit];
                        profit = max(buy, skip);
                    }
                    else{
                        int sell = prices[index] + dp[index+1][1][limit-1];
                        int skip =  dp[index+1][0][limit];
                        profit = max(sell, skip);
                    }
                    dp[index][isBuyable][limit] = profit;
                }
            }
        }

        return dp[0][1][2]; 
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();        
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for(int index=n-1; index>=0; index--){
            for(int isBuyable=0; isBuyable<=1; isBuyable++){
                for(int limit=1; limit<=2; limit++){
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

        return curr[1][2]; 
    }
};
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
                 Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
                 Total profit is 4 + 3 = 7.

Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
                 Total profit is 4.

Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:
    1 <= prices.length <= 3 * 10^4
    0 <= prices[i] <= 10^4
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int maxProfitUtil(vector<int>& prices, int isBuyable, int index){
        if(index == prices.size()){
            return 0;
        }

        int profit = 0;
        if(isBuyable){
            int buy = -prices[index] + maxProfitUtil(prices, 0, index+1);
            int skip =  maxProfitUtil(prices, 1, index+1);
            profit = max(buy, skip);
        }
        else{
            int sell = prices[index] + maxProfitUtil(prices, 1, index+1);
            int skip =  maxProfitUtil(prices, 0, index+1);
            profit = max(sell, skip);
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return maxProfitUtil(prices, 1, 0); 
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int maxProfitUtil(vector<int>& prices, int isBuyable, int index, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][isBuyable] != -1){
            return dp[index][isBuyable];
        }

        int profit = 0;
        if(isBuyable){
            int buy = -prices[index] + maxProfitUtil(prices, 0, index+1, dp);
            int skip =  maxProfitUtil(prices, 1, index+1, dp);
            profit = max(buy, skip);
        }
        else{
            int sell = prices[index] + maxProfitUtil(prices, 1, index+1, dp);
            int skip =  maxProfitUtil(prices, 0, index+1, dp);
            profit = max(sell, skip);
        }
        return dp[index][isBuyable] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return maxProfitUtil(prices, 1, 0, dp); 
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int index=n-1; index>=0; index--){
            for(int isBuyable=0; isBuyable<=1; isBuyable++){
                int profit = 0;
                if(isBuyable){
                    int buy = -prices[index] + dp[index+1][0];
                    int skip =  dp[index+1][1];
                    profit = max(buy, skip);
                }
                else{
                    int sell = prices[index] + dp[index+1][1];
                    int skip =  dp[index+1][0];
                    profit = max(sell, skip);
                }
                dp[index][isBuyable] = profit;
            }
        }

        return dp[0][1];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimizationjk
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        
        for(int index=n-1; index>=0; index--){
            for(int isBuyable=0; isBuyable<=1; isBuyable++){
                int profit = 0;
                if(isBuyable){
                    int buy = -prices[index] + next[0];
                    int skip =  next[1];
                    profit = max(buy, skip);
                }
                else{
                    int sell = prices[index] + next[1];
                    int skip =  next[0];
                    profit = max(sell, skip);
                }
                curr[isBuyable] = profit;
            }
            next = curr;
        }

        return curr[1];
    }
};
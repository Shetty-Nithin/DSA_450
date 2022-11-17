/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction
fee foreach transaction.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

Example 1:
    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: The maximum profit can be achieved by:
                - Buying at prices[0] = 1
                - Selling at prices[3] = 8
                - Buying at prices[4] = 4
                - Selling at prices[5] = 9
                The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
    Input: prices = [1,3,7,5,10,3], fee = 3
    Output: 6

Constraints:
    1 <= prices.length <= 5 * 10^4
    1 <= prices[i] < 5 * 10^4
    0 <= fee < 5 * 10^4
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
                    int sell = prices[index] + next[1] - fee;
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
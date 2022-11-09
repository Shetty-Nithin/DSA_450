/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a
total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Link : https://leetcode.com/problems/coin-change/description/

Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

Example 2:
    Input: coins = [2], amount = 3
    Output: -1

Example 3:
    Input: coins = [1], amount = 0
    Output: 0

Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion (TLE)
class Solution {
private:
    int coinChangeUtil(int currMinCoin, int minCoin, vector<int> &coins, int amount){
        if(amount == 0){
            return currMinCoin;
        }
        if(amount < 0){
            return INT_MAX;
        }

        for(int i=0; i<coins.size(); i++){
            currMinCoin++;
            minCoin = min(minCoin, coinChangeUtil(currMinCoin, minCoin, coins, amount-coins[i]));
            currMinCoin--;
        }

        return minCoin;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoin = INT_MAX;
        int currMinCoin = 0;
        minCoin = min(minCoin, coinChangeUtil(currMinCoin, minCoin, coins, amount-0));
        
        if(minCoin == INT_MAX) return -1;
        return minCoin;
    }
};

// Approach 2 : Recurssion (TLE)
class Solution {
private:
    int coinChangeUtil(vector<int> &coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        int minCoin = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = coinChangeUtil(coins, amount-coins[i]);
            if(ans != INT_MAX){
                minCoin = min(minCoin, 1+ans); // tail recurssion.(calculating the minCoins while returning from the recurssion)
            }
        }

        return minCoin;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoin = coinChangeUtil(coins, amount);
        
        if(minCoin == INT_MAX) return -1;
        return minCoin;
    }
};

// Approach 3 : Recurssion + Memoization (TLE)
class Solution {
private:
    int coinChangeUtil(vector<int> &coins, int amount, vector<int> minCoinsDP){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        if(minCoinsDP[amount] != -1){
            return minCoinsDP[amount];
        }

        int minCoin = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = coinChangeUtil(coins, amount-coins[i], minCoinsDP);
            if(ans != INT_MAX){
                minCoin = min(minCoin, 1+ans); // tail recurssion.(calculating the minCoins while returning from the recurssion)
            }
        }
        minCoinsDP[amount] = minCoin;

        return minCoin;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoinsDP(amount+1, -1); //saving the minCoins based on the remaining target values as a index
        int minCoin = coinChangeUtil(coins, amount, minCoinsDP);
        
        if(minCoin == INT_MAX) return -1;
        return minCoin;
    }
};

// Approach 4 : Bottoms-Up (Tabulation)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoinsDP(amount+1, INT_MAX);
        minCoinsDP[0] = 0;

        for(int i=1; i<=amount; i++){ // i = current amount
            for(int j=0; j<coins.size(); j++){ // j = each coin
                if(i-coins[j] >= 0 && minCoinsDP[i-coins[j]] != INT_MAX){
                    minCoinsDP[i] = min(minCoinsDP[i], 1+minCoinsDP[i-coins[j]]);
                }
            }
        }
        
        if(minCoinsDP[amount] == INT_MAX) return -1;
        return minCoinsDP[amount];
    }
};
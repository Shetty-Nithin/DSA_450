/*
You have n dice, and each die has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice,
so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
Link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

Example 1:
    Input: n = 1, k = 6, target = 3
    Output: 1
    Explanation: You throw one die with 6 faces. There is only one way to get a sum of 3.

Example 2:
    Input: n = 2, k = 6, target = 7
    Output: 6
    Explanation: You throw two dice, each with 6 faces. There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
    Input: n = 30, k = 30, target = 500
    Output: 222616187
    Explanation: The answer must be returned modulo 109 + 7.

Constraints:
    1 <= n, k <= 30
    1 <= target <= 1000
*/


#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int MOD = 1e9+7;
    int numRollsToTargetUtil(int dice, int face, int target){
        if(target < 0) return 0;
        if(dice == 0 && target != 0) return 0;
        if(dice != 0 && target == 0) return 0;
        if(dice == 0 && target == 0) return 1;

        int ans = 0;
        for(int i=1; i<=face; i++){
            ans = ans + numRollsToTargetUtil(dice-1, face, target-i);
        }

        return ans%MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target){
        return numRollsToTargetUtil(n, k, target);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int MOD = 1e9+7;
    int numRollsToTargetUtil(int dice, int face, int target, vector<vector<int>>& dp){
        if(target < 0) return 0;
        if(dice == 0 && target != 0) return 0;
        if(dice != 0 && target == 0) return 0;
        if(dice == 0 && target == 0) return 1;

        if(dp[dice][target] != -1){
            return dp[dice][target];
        }

        int ans = 0;
        for(int i=1; i<=face; i++){
            ans = (ans%MOD + (numRollsToTargetUtil(dice-1, face, target-i, dp)%MOD))%MOD;
        }

        return dp[dice][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return numRollsToTargetUtil(n, k, target, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int numRollsToTarget(int n, int k, int target){
        int MOD = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int dice=1; dice<=n; dice++){
            for(int tar=1; tar<=target; tar++){
                int ans = 0;
                for(int i=1; i<=k; i++){
                    if(tar-i >= 0){
                        ans = (ans%MOD + dp[dice-1][tar-i]%MOD)%MOD;
                    }
                }
                dp[dice][tar] = ans;
            }
        }

        return dp[n][target];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int numRollsToTarget(int n, int k, int target){
        int MOD = 1e9+7;
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        prev[0] = 1;

        for(int dice=1; dice<=n; dice++){
            for(int tar=1; tar<=target; tar++){
                int ans = 0;
                for(int i=1; i<=k; i++){
                    if(tar-i >= 0){
                        ans = (ans%MOD + prev[tar-i]%MOD)%MOD;
                    }
                }
                curr[tar] = ans;
            }
            prev = curr;
        }

        return prev[target];
    }
};
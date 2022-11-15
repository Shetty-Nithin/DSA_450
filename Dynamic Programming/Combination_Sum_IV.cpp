/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations
that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.
Link : https://leetcode.com/problems/combination-sum-iv/

Example 1:
    Input: nums = [1,2,3], target = 4
    Output: 7
    Explanation:
        The possible combination ways are:
        (1, 1, 1, 1)
        (1, 1, 2)
        (1, 2, 1)
        (1, 3)
        (2, 1, 1)
        (2, 2)
        (3, 1)
        Note that different sequences are counted as different combinations.

Example 2:
    Input: nums = [9], target = 3
    Output: 0

Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 1000
    All the elements of nums are unique.
    1 <= target <= 1000
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private: 
    int combinationSum4Util(vector<int> &nums, int target){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += combinationSum4Util(nums, target-nums[i]);
        }

        return ans;
    };
public:
    int combinationSum4(vector<int>& nums, int target) {
        return combinationSum4Util(nums, target);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private: 
    int combinationSum4Util(vector<int> &nums, int target, vector<int> &dp){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += combinationSum4Util(nums, target-nums[i], dp);
        }
        dp[target] = ans;

        return dp[target];
    };
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return combinationSum4Util(nums, target, dp);
    }
};

// Approach 3 : Bottoms-Up/Tabulation
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0); // to prevent the signed int overflow
        dp[0] = 1;
        
        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(i-nums[j] >= 0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }

        return dp[target];
    }
};
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.
// Link : https://leetcode.com/problems/house-robber/

Example 1:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                 Total amount you can rob = 1 + 3 = 4.

Example 2:
    Input: nums = [2,7,9,3,1]
    Output: 12
    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
                 Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 400
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private: 
    int robUtil(vector<int> &nums, int n, int i){
        if(i >= n) return 0;
        else if(i == n-1) return nums[i];

        int ans = max((nums[i] + robUtil(nums, n, i+2)), robUtil(nums, n, i+1));
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return robUtil(nums, n, 0);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private: 
    int robUtil(vector<int> &nums, int n, int i, vector<int> &maxAmounts){
        if(i >= n) return 0;
        else if(i == n-1) return nums[i];

        if(maxAmounts[i] != -1){
            return maxAmounts[i];
        }
        int ans = max((nums[i] + robUtil(nums, n, i+2, maxAmounts)), robUtil(nums, n, i+1, maxAmounts));
        maxAmounts[i] = ans;
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxAmounts(n, -1);
        return robUtil(nums, n, 0, maxAmounts);
    }
};

// Approach 3 : Bottoms-Up/Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> maxAmounts(n, 0);
        maxAmounts[n-1] = nums[n-1];
        maxAmounts[n-2] = max(nums[n-2], nums[n-1]);

        for(int i=n-3; i>=0; i--){
            int incl = nums[i] + maxAmounts[i+2];
            int excl = maxAmounts[i+1];

            maxAmounts[i] = max(incl, excl);
        }

        return maxAmounts[0];
    }
};

// Approach 4 : Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int prev2 = nums[n-1];
        int prev1 = max(nums[n-2], nums[n-1]);

        for(int i=n-3; i>=0; i--){
            int incl = nums[i] + prev2;
            int excl = prev1;

            prev2 = prev1;
            prev1 = max(incl, excl);
        }

        return prev1;
    }
};
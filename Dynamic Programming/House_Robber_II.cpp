/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two
adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you
can rob tonight without alerting the police.
Link : https://leetcode.com/problems/house-robber-ii/description/

Example 1:
    Input: nums = [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                 Total amount you can rob = 1 + 3 = 4.

Example 3:
    Input: nums = [1,2,3]
    Output: 3

Constraints: 
    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int robUtil(vector<int> arr, int n, int i){
        if(i >= n) return 0;
        else if(i == n-1) return arr[i];

        int ans = max((arr[i] + robUtil(arr, n, i+2)), robUtil(arr, n, i+1));
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> first, second;

        for(int i=0; i<n; i++){
            if(i != n-1){
                first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);;
            }
        }

        return max(robUtil(first, n-1, 0), robUtil(second, n-1, 0));
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int robUtil(vector<int> arr, int n, int i, vector<int> &maxAmounts){
        if(i >= n) return 0;
        else if(i == n-1) return arr[i];

        if(maxAmounts[i] != -1){
            return maxAmounts[i];
        }
        int ans = max((arr[i] + robUtil(arr, n, i+2, maxAmounts)), robUtil(arr, n, i+1, maxAmounts));
        maxAmounts[i] = ans;
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> first, second;

        for(int i=0; i<n; i++){
            if(i != n-1){
                first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);;
            }
        }
        vector<int> firstAmounts(n-1, -1);
        vector<int> secondAmounts(n-1, -1);
        return max(robUtil(first, n-1, 0, firstAmounts), robUtil(second, n-1, 0, secondAmounts));
    }
};

// Approach 3 : Bottoms-Up/Tabulation 
class Solution {
private:
    int robUtil(vector<int> arr){
        int n = arr.size();
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);

        vector<int> maxAmounts(n, 0);
        maxAmounts[n-1] = arr[n-1];
        maxAmounts[n-2] = max(arr[n-2], arr[n-1]);

        for(int i=n-3; i>=0; i--){
            int incl = arr[i] + maxAmounts[i+2];
            int excl = maxAmounts[i+1];

            maxAmounts[i] = max(incl, excl);
        }

        return maxAmounts[0];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> first, second;

        for(int i=0; i<n; i++){
            if(i != n-1){
                first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);;
            }
        }

        return max(robUtil(first), robUtil(second));
    }
};

// Approach 4 : Space Optimization
class Solution {
private:
    int robUtil(vector<int> arr){
        int n = arr.size();
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);

        int prev2 = arr[n-1];
        int prev1 = max(arr[n-2], arr[n-1]);

        for(int i=n-3; i>=0; i--){
            int incl = arr[i] + prev2;
            int excl = prev1;

            prev2 = prev1;
            prev1 = max(incl, excl);
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> first, second;

        for(int i=0; i<n; i++){
            if(i != n-1){
                first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);;
            }
        }

        return max(robUtil(first), robUtil(second));
    }
};
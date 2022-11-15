/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets
such that the sum of elements in both subsets is equal.
Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

Example 1:
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 100
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    bool canPartitionUtil(vector<int>& nums, int index, int target){
        if(index >= nums.size()) return 0;
        if(target < 0) return 0;
        if(target == 0) return 1;

        int include = canPartitionUtil(nums, index+1, target-nums[index]);
        int exclude = canPartitionUtil(nums, index+1, target);

        return include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        
        if(sum%2 != 0) return false;
        return canPartitionUtil(nums, 0, sum/2);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    bool canPartitionUtil(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if(index >= nums.size()) return 0;
        if(target < 0) return 0;
        if(target == 0) return 1;

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int include = canPartitionUtil(nums, index+1, target-nums[index], dp);
        int exclude = canPartitionUtil(nums, index+1, target, dp);

        return dp[index][target] = include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((sum/2)+1, -1));
        return canPartitionUtil(nums, 0, sum/2, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n+1, vector<int>((sum/2)+1, 0));
        
        for(int i=0; i<=n; i++){
            dp[i][0] = 1; // base case
        }
        for(int index=n-1; index>=0; index--){
            for(int target=0; target<=sum/2; target++){
                int include = 0;
                if(target-nums[index] >= 0){
                    include = dp[index+1][target-nums[index]];
                }
                int exclude = dp[index+1][target];

                dp[index][target] = include || exclude;
            }
        }

        return dp[0][sum/2];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        
        if(sum%2 != 0) return false;
        vector<int> curr((sum/2)+1, 0);
        vector<int> next((sum/2)+1, 0);
        
        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1; index>=0; index--){
            for(int target=0; target<=sum/2; target++){
                int include = 0;
                if(target-nums[index] >= 0){
                    include = next[target-nums[index]];
                }
                int exclude = next[target];

                curr[target] = include || exclude;
            }
            next = curr;
        }

        return curr[sum/2];
    }
};
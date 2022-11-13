/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
Link : https://leetcode.com/problems/longest-increasing-subsequence/description/

Example 1:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
    Input: nums = [0,1,0,3,2,3]
    Output: 4

Example 3:
    Input: nums = [7,7,7,7,7,7,7]
    Output: 1

Constraints:
    1 <= nums.length <= 2500
    104 <= nums[i] <= 10^4
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Naive (TLE)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis = 1;
        int nextSmall = 0;
        for(int i=1; i<nums.size(); i++){
            int count = 1;
            bool nextSmallUpdated = false;
            for(int j=i; j<nums.size(); j++){
                if(nums[j] > nums[j-1]){
                    count++;
                }else if(!nextSmallUpdated){
                    nextSmallUpdated = true;
                    nextSmall = j;
                }
            }
            lis = max(lis, count);
            i = nextSmall+1;
        }
        
        return lis;
    }
};

// Approach 2 : Recurssion (TLE)
class Solution {
private:
    int lengthOfLISUtil(vector<int>& nums, int n, int currIndex, int prevIndex){
        if(currIndex >= n){
            return 0;
        }

        int include = 0;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
            include = 1 + lengthOfLISUtil(nums, n, currIndex+1, currIndex);
        }
        int exclude = lengthOfLISUtil(nums, n, currIndex+1, prevIndex);

        return max(include, exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lengthOfLISUtil(nums, n, 0, -1);
    }
};

// Approach 3 : Recurssion + Memoization
class Solution {
private:
    int lengthOfLISUtil(vector<int>& nums, int n, int currIndex, int prevIndex, vector<vector<int>>& dp){
        if(currIndex >= n){
            return 0;
        }
        if(dp[currIndex][prevIndex+1] != -1){
            return dp[currIndex][prevIndex+1];
        }

        int include = 0;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
            include = 1 + lengthOfLISUtil(nums, n, currIndex+1, currIndex, dp);
        }
        int exclude = lengthOfLISUtil(nums, n, currIndex+1, prevIndex, dp);

        return dp[currIndex][prevIndex+1] = max(include, exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n ,vector<int>(n+1, -1));
        return lengthOfLISUtil(nums, n, 0, -1, dp);
    }
};

// Approach 4 : Bottom-Up/Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 ,vector<int>(n+1, 0));
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};


// Approach 5 : Bottom-Up/Tabulation with optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextRow[curr+1];
                }
                int exclude = nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
};

// Approach 6 : DP with Binary Search
class Solution {
private:
    int DPwithBinary(vector<int>& nums, int n){
        if(n == 0){
            return 0;
        }

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=0; i<n; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // finding the index of just larger element
                int index = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return DPwithBinary(nums, n);
    }
};
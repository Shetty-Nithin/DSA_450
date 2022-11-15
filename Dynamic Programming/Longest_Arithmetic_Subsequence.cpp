/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
Recall that a subsequence of an array nums is a list nums[i1], nums[i2], ..., nums[ik] with 
0 <= i1 < i2 < ... < ik <= nums.length - 1, and that a sequence seq is arithmetic if seq[i+1] - seq[i] are 
all the same value (for 0 <= i < seq.length - 1).
Link : https://leetcode.com/problems/longest-arithmetic-subsequence/description/

Example 1:
    Input: nums = [3,6,9,12]
    Output: 4
    Explanation: The whole array is an arithmetic sequence with steps of length = 3.

Example 2:
    Input: nums = [9,4,7,2,10]
    Output: 3
    Explanation: The longest arithmetic subsequence is [4,7,10].

Example 3:
    Input: nums = [20,1,15,3,10,5,8]
    Output: 4
    Explanation: The longest arithmetic subsequence is [20,15,10,5].

Constraints:
    2 <= nums.length <= 1000
    0 <= nums[i] <= 500
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int longestArithSeqLengthUtil(vector<int>& nums, int index, int diff){
        if(index < 0){
            return 0;
        }

        int ans = 0;
        for(int k=index-1; k>=0; k--){
            if(nums[index]-nums[k] == diff){
                ans = max(ans, 1+longestArithSeqLengthUtil(nums, k, diff));
            }
        }
        return ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }

        int longest = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                longest = max(longest, 2+longestArithSeqLengthUtil(nums, i, nums[j]-nums[i]));
            }
        }

        return longest;
    }
};

// // Approach 2 : Recurssion + Memoization
// class Solution {
// private:
//     int longestArithSeqLengthUtil(vector<int>& nums, int index, int diff, unordered_map<int, int> dp[]){
//         if(index < 0){
//             return 0;
//         }
//         if(dp[index].count(diff)){
//             return dp[index][diff];
//         }

//         int ans = 0;
//         for(int k=index-1; k>=0; k--){
//             if(nums[index]-nums[k] == diff){
//                 ans = max(ans, 1+longestArithSeqLengthUtil(nums, k, diff, dp));
//             }
//         }
//         return dp[index][diff] = ans;
//     }
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n <= 2){
//             return n;
//         }

//         unordered_map<int, int> dp[n+1];
//         int longest = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 longest = max(longest, 2+longestArithSeqLengthUtil(nums, i, nums[j]-nums[i], dp));
//             }
//         }

//         return longest;
//     }
// };

// // Approach 3 : Bottom-Up/Tabulation
// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n <= 2){
//             return n;
//         }

//         unordered_map<int, int> dp(n+1);
//         int longest = 0;
//         for(int i=1; i<n; i++){
//             for(int j=0; j<i; j++){
//                 int diff = nums[i]-nums[j];
//                 int count = 1;

//                 // check if ans is already present
//                 if(dp[j].count(diff)){
//                     count = dp[j][diff];
//                 }
//                 dp[i][diff] = 1+count;
//                 longest = max(longest, dp[i][diff]);
//             }
//         }

//         return longest;
//     }
// };

// Approach 4 : Bottom-Up/Tabulation
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[2000][2000]={0};
        int longest=0;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = nums[i]-nums[j]+1000; //to avoid negative value.
                dp[i][diff] = dp[j][diff]+1;
                longest = max(longest, dp[i][diff]);
            }
        }
        return longest+1;
    }
};
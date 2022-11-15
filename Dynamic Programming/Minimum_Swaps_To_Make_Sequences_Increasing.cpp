/*
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i]
with nums2[i].
For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4]
and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated
so that the given input always makes it possible.
An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].
Link : https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

Example 1:
    Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
    Output: 1
    Explanation: Swap nums1[3] and nums2[3]. Then the sequences are:
                 nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
                 which are both strictly increasing.

Example 2:
    Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
    Output: 1

Constraints:
    2 <= nums1.length <= 10^5
    nums2.length == nums1.length
    0 <= nums1[i], nums2[i] <= 2 * 10^5
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int minSwapUtil(vector<int>& nums1, vector<int>& nums2, int index, bool swaped){
        if(index == nums1.size()){
            return 0;
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swaped){
            swap(prev1, prev2);
        }

        //no swap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = minSwapUtil(nums1, nums2, index+1, 0);
        }
        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1+minSwapUtil(nums1, nums2, index+1, 1));
        }

        return ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2){
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swaped = 0;
        return minSwapUtil(nums1, nums2, 1, swaped);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int minSwapUtil(vector<int>& nums1, vector<int>& nums2, int index, bool swaped, vector<vector<int>>& dp){
        if(index == nums1.size()){
            return 0;
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swaped){
            swap(prev1, prev2);
        }
        if(dp[index][swaped] != -1){
            return dp[index][swaped];
        }


        //no swap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = minSwapUtil(nums1, nums2, index+1, 0, dp);
        }
        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1+minSwapUtil(nums1, nums2, index+1, 1, dp));
        }

        return dp[index][swaped] = ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2){
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swaped = 0;
        vector<vector<int>> dp(nums1.size(), vector<int> (2, -1));
        return minSwapUtil(nums1, nums2, 1, swaped, dp);
    }
};

// Approach 3 : Buttom-Up/Tabulation
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2){
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        bool swaped = 0;

        for(int index=n-1; index>=1; index--){
            for(int swaped=1; swaped>=0; swaped--){

                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swaped){
                    swap(prev1, prev2);
                }

                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = dp[index+1][0];
                }
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1+dp[index+1][1]);
                }

                dp[index][swaped] = ans;
            }
        }
        return dp[1][0];
    }
};

// Approach 4 : Buttom-Up/Tabulation with space optimization
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2){
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        bool swaped = 0;

        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;

        for(int index=n-1; index>=1; index--){
            for(int swaped=1; swaped>=0; swaped--){

                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swaped){
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = noswap;
                }
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1+swap);
                }

                if(swaped){
                    currswap = ans;
                }else{
                    currnoswap = ans;
                }
            }
            noswap = currnoswap;
            swap = currswap;
        }
        return min(swap, noswap);
    }
};
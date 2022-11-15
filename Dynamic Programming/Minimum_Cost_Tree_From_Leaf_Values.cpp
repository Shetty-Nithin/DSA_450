/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.
It is guaranteed this sum fits into a 32-bit integer.
A node is a leaf if and only if it has zero children.
Link : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

Example 1:
    Input: arr = [6,2,4]
    Output: 32
    Explanation: There are two possible trees shown.
                 The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 3:
    Input: arr = [4,11]
    Output: 44

Constraints:
    2 <= arr.length <= 40
    1 <= arr[i] <= 15
    It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int mctFromLeafValuesUtil(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right){
        if(left == right) return 0;

        int mini = INT_MAX;
        for(int i=left; i<right; i++){
            mini = min(mini, maxi[{left, i}]*maxi[{i+1, right}] + mctFromLeafValuesUtil(arr, maxi, left, i) + mctFromLeafValuesUtil(arr, maxi, i+1, right));
        }

        return mini;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        return mctFromLeafValuesUtil(arr, maxi, 0, arr.size()-1);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int mctFromLeafValuesUtil(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp){
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int mini = INT_MAX;
        for(int i=left; i<right; i++){
            mini = min(mini, maxi[{left, i}]*maxi[{i+1, right}] + mctFromLeafValuesUtil(arr, maxi, left, i, dp) + mctFromLeafValuesUtil(arr, maxi, i+1, right, dp));
        }

        return dp[left][right] = mini;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return mctFromLeafValuesUtil(arr, maxi, 0, arr.size()-1, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation #TODO
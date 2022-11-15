/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return
the maximum possible sum of slice sizes that you can pick.
Link : https://leetcode.com/problems/pizza-with-3n-slices/

Example 1:
    Input: slices = [1,2,3,4,5,6]
    Output: 10
    Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. 
                Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively.
                Total = 4 + 6.

Example 2:
    Input: slices = [8,9,8,6,1,1]
    Output: 16
    Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick
                slices of size 8.

Constraints:
    3 * n == slices.length
    1 <= slices.length <= 500
    1 <= slices[i] <= 1000
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int maxSizeSlicesUtil(int startIndex, int endIndex, vector<int>& slices, int n){
        if(n == 0 || startIndex > endIndex){
            return 0;
        }

        int include = slices[startIndex] + maxSizeSlicesUtil(startIndex+2, endIndex, slices, n-1);
        int exclude = maxSizeSlicesUtil(startIndex+1, endIndex, slices, n);

        return max(include, exclude);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = maxSizeSlicesUtil(0, k-2, slices, k/3);
        int case2 = maxSizeSlicesUtil(1, k-1,  slices, k/3);

        return max(case1, case2);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int maxSizeSlicesUtil(int startIndex, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp){
        if(n == 0 || startIndex > endIndex){
            return 0;
        }
        if(dp[startIndex][n] != -1){
            return dp[startIndex][n];
        }

        int include = slices[startIndex] + maxSizeSlicesUtil(startIndex+2, endIndex, slices, n-1, dp);
        int exclude = maxSizeSlicesUtil(startIndex+1, endIndex, slices, n, dp);

        return dp[startIndex][n] = max(include, exclude);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int> (k, -1));
        vector<vector<int>> dp2(k, vector<int> (k, -1));

        int case1 = maxSizeSlicesUtil(0, k-2, slices, k/3, dp1);
        int case2 = maxSizeSlicesUtil(1, k-1,  slices, k/3, dp2);

        return max(case1, case2);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int> (k+2, 0));
        vector<vector<int>> dp2(k+2, vector<int> (k+2, 0));

        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int include = slices[index] + dp1[index+2][n-1];
                int exclude = dp1[index+1][n];

                dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k/3];

        for(int index=k-1; index>=1; index--){
            for(int n=1; n<=k/3; n++){
                int include = slices[index] + dp2[index+2][n-1];
                int exclude = dp2[index+1][n];

                dp2[index][n] = max(include, exclude);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<int> prev1(k+2, 0);
        vector<int> curr1(k+2, 0);
        vector<int> next1(k+2, 0);

        vector<int> prev2(k+2, 0);
        vector<int> curr2(k+2, 0);
        vector<int> next2(k+2, 0);

        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int include = slices[index] + next1[n-1];
                int exclude = curr1[n];

                prev1[n] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k/3];

        for(int index=k-1; index>=1; index--){
            for(int n=1; n<=k/3; n++){
                int include = slices[index] + next2[n-1];
                int exclude = curr2[n];

                prev2[n] = max(include, exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];

        return max(case1, case2);
    }
};
/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence,
return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted
without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
Link : https://leetcode.com/problems/longest-common-subsequence/description/

Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.


Constraints:
    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int longestCommonSubsequenceUtil(string text1, string text2, int i, int j){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + longestCommonSubsequenceUtil(text1, text2, i+1, j+1);
        }else{
            int i_next = longestCommonSubsequenceUtil(text1, text2, i+1, j);
            int j_next = longestCommonSubsequenceUtil(text1, text2, i, j+1);
            ans = max(i_next, j_next);
        }
        return ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return longestCommonSubsequenceUtil(text1, text2, 0, 0);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int longestCommonSubsequenceUtil(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + longestCommonSubsequenceUtil(text1, text2, i+1, j+1, dp);
        }else{
            int i_next = longestCommonSubsequenceUtil(text1, text2, i+1, j, dp);
            int j_next = longestCommonSubsequenceUtil(text1, text2, i, j+1, dp);
            ans = max(i_next, j_next);
        }
        return dp[i][j] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return longestCommonSubsequenceUtil(text1, text2, 0, 0, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        
        for(int i=text1.length()-1; i>=0; i--){
            for(int j=text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }else{
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.length()+1, 0);
        vector<int> next(text2.length()+1, 0);
        
        for(int i=text1.length()-1; i>=0; i--){
            for(int j=text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + next[j+1];
                }else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};

// Approach 5 : Top-Down/Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                int ans = 0;
                if(text1[i-1] == text2[j-1]){
                    ans = 1 + dp[i-1][j-1];
                }else{
                    ans = max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[m][n];
    }
};
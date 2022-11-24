/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Link  : https://leetcode.com/problems/wildcard-matching/

Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

Example 2:
    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.

Example 3:
    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 
Constraints:
    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int isMatchUtil(string& s, string& p, int sLen, int pLen){
        if(sLen<0 && pLen<0){
            return true;
        }
        if(sLen>=0 && pLen<0){
            return false;
        }
        if(sLen<0 && pLen>=0){
            for(int k=0; k<=pLen; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(s[sLen] == p[pLen] || p[pLen] == '?'){
            return isMatchUtil(s, p, sLen-1, pLen-1);
        }
        else if(p[pLen] == '*'){
            return (isMatchUtil(s, p, sLen-1, pLen) || isMatchUtil(s, p, sLen, pLen-1));
        }
        else return false;
    }
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();

        return isMatchUtil(s, p, sLen-1, pLen-1);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int isMatchUtil(string& s, string& p, int sLen, int pLen, vector<vector<int>>& dp){
        if(sLen==0 && pLen==0){
            return true;
        }
        if(sLen>0 && pLen==0){
            return false;
        }
        if(sLen==0 && pLen>0){
            for(int k=1; k<=pLen; k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }
        if(dp[sLen][pLen] != -1){
            return dp[sLen][pLen];
        }

        if(s[sLen-1] == p[pLen-1] || p[pLen-1] == '?'){
            return dp[sLen][pLen] = isMatchUtil(s, p, sLen-1, pLen-1, dp);
        }
        else if(p[pLen-1] == '*'){
            return dp[sLen][pLen] = (isMatchUtil(s, p, sLen-1, pLen, dp) || isMatchUtil(s, p, sLen, pLen-1, dp));
        }
        else return dp[sLen][pLen] = false;
    }
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        vector<vector<int>> dp(sLen+1, vector<int>(pLen+1, -1));
        return isMatchUtil(s, p, sLen, pLen, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        vector<vector<int>> dp(sLen+1, vector<int>(pLen+1, 0));
        dp[0][0] = true;
        for(int j=1; j<=pLen; j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        for(int i=1; i<=sLen; i++){
            for(int j=1; j<=pLen; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else dp[i][j] = false;
            }
        }
        return dp[sLen][pLen];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        vector<int> curr(pLen+1, 0);
        vector<int> prev(pLen+1, 0);
        prev[0] = true;
        for(int j=1; j<=pLen; j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        
        for(int i=1; i<=sLen; i++){
            for(int j=1; j<=pLen; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[j-1] == '*'){
                    curr[j] = (prev[j] || curr[j-1]);
                }
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[pLen];
    }
};
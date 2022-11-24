/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
Link : https://leetcode.com/problems/edit-distance/description/

Example 1:
    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')

Example 2:
    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
 
Constraints:
    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.

*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:    
    int minDistanceUtil(string word1, string word2, int w1, int w2){
        if(w1 == word1.length()){
            return word2.length()-w2; // when first word is smaller than the second word
        }
        if(w2 == word2.length()){
            return word1.length()-w1;
        }

        int ans = 0;
        if(word1[w1] == word2[w2]){
            return minDistanceUtil(word1, word2, w1+1, w2+1);
        }
        else {
            int insertAns = 1 + minDistanceUtil(word1, word2, w1, w2+1);
            int deleteAns = 1 + minDistanceUtil(word1, word2, w1+1, w2);
            int replaceAns = 1 + minDistanceUtil(word1, word2, w1+1, w2+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
public:
    int minDistance(string word1, string word2) {
        return minDistanceUtil(word1, word2, 0, 0);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:    
    int minDistanceUtil(string word1, string word2, int w1, int w2, vector<vector<int>>& dp){
        if(w1 == word1.length()){
            return word2.length()-w2; // when first word is smaller than the second word
        }
        if(w2 == word2.length()){
            return word1.length()-w1;
        }
        if(dp[w1][w2] != -1){
            return dp[w1][w2];
        }

        int ans = 0;
        if(word1[w1] == word2[w2]){
            return minDistanceUtil(word1, word2, w1+1, w2+1, dp);
        }
        else {
            int insertAns = 1 + minDistanceUtil(word1, word2, w1, w2+1, dp);
            int deleteAns = 1 + minDistanceUtil(word1, word2, w1+1, w2, dp);
            int replaceAns = 1 + minDistanceUtil(word1, word2, w1+1, w2+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[w1][w2] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return minDistanceUtil(word1, word2, 0, 0, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        vector<vector<int>> dp(w1+2, vector<int>(w2+2, 0));
        
        for(int j=0; j<w2; j++){
            dp[w1][j] = w2-j;
        }
        for(int i=0; i<w1; i++){
            dp[i][w2] = w1-i;
        }

        for(int i=w1-1; i>=0; i--){
            for(int j=w2-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = dp[i+1][j+1];
                }
                else {
                    int insertAns = 1 + dp[i][j+1];
                    int deleteAns = 1 + dp[i+1][j];
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
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
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();

        if(w1 == 0) return w2;
        if(w2 == 0) return w1;

        vector<int> curr(w2+1, 0);
        vector<int> next(w2+1, 0);
        
        for(int j=0; j<w2; j++){
            next[j] = w2-j;
        }

        for(int i=w1-1; i>=0; i--){
            for(int j=w2-1; j>=0; j--){
                curr[w2] = w1-i;
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = next[j+1];
                }
                else {
                    int insertAns = 1 + curr[j+1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];  
    }
};
/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing
the order of the remaining elements.
Link : https://leetcode.com/problems/longest-palindromic-subsequence/

Example 1:
    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".

Constraints:
    1 <= s.length <= 1000
    s consists only of lowercase English letters.
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());

        vector<int> curr(s.length()+1, 0);
        vector<int> next(s.length()+1, 0);
        
        for(int i=s.length()-1; i>=0; i--){
            for(int j=revS.length()-1; j>=0; j--){
                int ans = 0;
                if(s[i] == revS[j]){
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
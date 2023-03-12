/*
Given a string S, check if it is palindrome or not.

Link : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

Example 1:
    Input: S = "abba"
    Output: 1
    Explanation: S is a palindrome

Example 2:
    Input: S = "abc" 
    Output: 0
    Explanation: S is not a palindrome

Constraints:
    Expected Time Complexity: O(Length of S)
    Expected Auxiliary Space: O(1)
    1 <= Length of S<= 105
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int isPalindrome(string S){
	    int l = 0;
	    int r = S.length()-1;
	    
	    while(l <= r){
	        if(S[l++] != S[r--]) return 0;
	    }
	    
	    return 1;
	}

};


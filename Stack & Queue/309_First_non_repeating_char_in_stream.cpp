/*
Given an input stream of A of n characters consisting only of lower case 
alphabets. The task is to find the first non repeating character, each 
time a character is inserted to the stream. If there is no such character 
then append '#' to the answer.

Link : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

Example 1:
    Input: A = "aabc"
    Output: "a#bb"

    Explanation: For every character first non
    repeating character is as follow-
    "a" - first non-repeating character is 'a'
    "aa" - no non-repeating character so '#'
    "aab" - first non-repeating character is 'b'
    "aabc" - first non-repeating character is 'b'

Example 2:
    Input: A = "zz"
    Output: "z#"

    Explanation: For every character first non
    repeating character is as follow-
    "z" - first non-repeating character is 'z'
    "zz" - no non-repeating character so '#'

 

Constraints:
    1 <= n <= 10^5

    Expected Time Complexity: O(26 * n)
    Expected Space Complexity: O(26)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	string FirstNonRepeating(string A){
	    map<char, int> count;
	    queue<char> q;
	    string ans = "";
	    
	    for(int i=0; i<A.length(); i++){
	        char ch = A[i];
	        count[ch]++;
	        q.push(A[i]);
	        
	        while(!q.empty()){
	            if(count[q.front()] > 1){
	                q.pop();
	            }else{
	                ans.push_back(q.front());
	                break;
	            }
	        }
	        
	        if(q.empty()){
	            ans.push_back('#');
	        }
	    }
	    return ans;
	}
};
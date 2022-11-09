/*
A celebrity is a person who is known to all but does not know anyone at 
a party. If you go to a party of N people, find if there is a celebrity 
in the party or not.
A square NxN matrix M[][] is used to represent people at the party such 
that if an element of row i and column j  is set to 1 it means ith 
person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.

Link : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

Example 1:
    Input:
    N = 3
    M[][] = {{0 1 0},
             {0 0 0}, 
             {0 1 0}}
    Output: 1
    Explanation: 0th and 2nd person both
    know 1. Therefore, 1 is the celebrity. 

Example 2:
    Input:
    N = 2
    M[][] = {{0 1},  \
             {1 0}}
    Output: -1
    Explanation: The two people at the party both
    know each other. None of them is a celebrity.

Constraints:
    2 <= N <= 3000
    0 <= M[][] <= 1

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            int person1 = s.top();
            s.pop();
            int person2 = s.top();
            s.pop();
            
            if(M[person1][person2] == 1){
                s.push(person2); // person 2 is celebrity
            }else{
                s.push(person1); // if person 1 doesnt know person2, it means, person1 could be the celebrity or there is no celebrity.
            }
        }
        
        int ans = s.top();
        
        int zeroCount = 0;
        int oneCount = 0;
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0){
                zeroCount++;
            }
            if(M[i][ans] == 1){
                oneCount++;
            }
        }
        
        if(zeroCount != n || oneCount != n-1){ // horizontal and vertical
            return -1;
        }else{
            return ans;
        }
    }
};
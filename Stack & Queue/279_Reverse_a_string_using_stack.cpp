/*
You are given a string S, the task is to reverse the string using stack.

Link : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

Example 1:
    Input: S="GeeksforGeeks"
    Output: skeeGrofskeeG

Constraints:
    1 ≤ length of the string ≤ 100

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/


#include<iostream>
#include<stack>
using namespace std;

char* reverse(char *S, int len)
{
    stack<int> stk;
    for(int i=0; i<len; i++){
        stk.push(S[i]);
    }
    
    int i=0;
    while(!stk.empty()){
        S[i] = stk.top();
        stk.pop();
        i++;
    }

    return S;
}
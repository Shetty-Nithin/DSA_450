/*
Given a Queue Q containing N elements. The task is to reverse the Queue. 
Your task is to complete the function rev(), that reverses the N elements 
of the queue.

Link : https://practice.geeksforgeeks.org/problems/queue-reversal/1

Example 1:
    Input:
    6
    4 3 1 10 2 6

    Output: 
    6 2 10 1 3 4

    Explanation: 
    After reversing the given
    elements of the queue , the resultant
    queue will be 6 2 10 1 3 4.

Example 2:
    Input:
    4
    4 3 2 1 

    Output: 
    1 2 3 4

    Explanation: 
    After reversing the given
    elements of the queue , the resultant
    queue will be 1 2 3 4.


Constraints:
    1 ≤ N ≤ 105
    1 ≤ elements of Queue ≤ 10^5

    Expected Time Complexity : O(n)
    Expected Auxilliary Space : O(n)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    return q;
}
/*
Find the largest rectangular area possible in a given histogram where 
the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have the same width and the width 
is 1 unit, there will be N bars height of each bar will be given by the 
array arr.

Link : https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

Example 1:
    Input:
    N = 7
    arr[] = {6,2,5,4,5,1,6}

    Output: 12

Example 2:
    Input:
    N = 8
    arr[] = {7 2 8 9 1 3 6 5}
             0 1 2 3 4 5 6 7 - index
    Output: 16

    Explanation: Maximum size of the histogram 
    will be 8  and there will be 2 consecutive 
    histogram. And hence the area of the 
    histogram will be 8x2 = 16.

Constraints:
    1 ≤ N ≤ 10^6
    1 ≤ arr[i] ≤ 10^12

    Expected Time Complxity : O(N)
    Expected Auxilliary Space : O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElementsInd(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top(); // next smaller element for arr[i]
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElementsInd(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElementsInd(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElementsInd(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int h = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            
            int newArea = h*b;
            area = max(area, newArea);
        }
        
        return area;
    }
};
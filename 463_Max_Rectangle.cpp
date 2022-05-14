/*
Given a rows x cols binary matrix filled with 0's and 1's, find the 
largest rectangle containing only 1's and return its area.

Link : https://practice.geeksforgeeks.org/problems/max-rectangle/1
Link : https://leetcode.com/problems/maximal-rectangle/

Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.

Example 2:
    Input: matrix = [["0"]]
    Output: 0

Example 3:
    Input: matrix = [["1"]]
    Output: 1
 
Constraints:
    rows == matrix.length
    cols == matrix[i].length
    1 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.
    
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    vector<int> nextSmallerElementsInd(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElementsInd(int *arr, int n){
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
    
    int largestRectangleArea(int *heights, int n) {
        
        vector<int> next(n);
        next = nextSmallerElementsInd(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElementsInd(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            
            int newArea = l*b;
            area = max(area, newArea);
        }
        
        return area;
    }
  public:
    int maxArea(int M[1000][1000], int n, int m) {
        
        int area = largestRectangleArea(M[0], m);
        
        for(int i=1; i<n; i++){
            for(int j=-0; j<m; j++){
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }else{
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        
        return area;
    }
};

// Try the same problem in leetcode. Small variatin is present.
/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.
Link  : https://leetcode.com/problems/maximal-rectangle/description/

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
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nextSmallerElementsInd(vector<int> arr, int n){
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
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> height(matrix[0].size(), 0);
        int maxi = INT_MIN;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<height.size(); j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(height));
        }
        return maxi;
    }
};
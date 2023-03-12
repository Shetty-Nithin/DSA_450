/*
Given an array Arr of N positive integers. Your task is to find the elements
whose value is equal to that of its index value ( Consider 1-based indexing ).

Link : https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1

Example 1:
    Input:
    N = 5
    Arr[] = {15, 2, 45, 12, 7}
    Output: 2
    Explanation: Only Arr[2] = 2 exists here.

Example 2:
    Input: 
    N = 1
    Arr[] = {1}
    Output: 1
    Explanation: Here Arr[1] = 1 exists.

Constraints:
    1 ≤ N ≤ 105
    1 ≤ Arr[i] ≤ 106

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int> ans;
	    for(int i=0; i<n; i++){
	        if(arr[i] == i+1){
	            ans.push_back(i+1);
	        }
	    }
	    return ans;
	}
};
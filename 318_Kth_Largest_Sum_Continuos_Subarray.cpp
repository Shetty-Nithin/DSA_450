/*
Given an array of integers. Write a program to find the K-th largest sum 
of contiguous subarray within the array of numbers which has negative and
positive numbers.

Link : https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/
Link : https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398

Examples 1: 
    Input: a[] = {20, -5, -1} 
            k = 3

    Output: 14

    Explanation: All sum of contiguous 
    subarrays are (20, 15, 14, -5, -6, -1) 
    so the 3rd largest sum is 14.

Examples 1: 
    Input: a[] = {10, -10, 20, -40} 
            k = 6
            
    Output: -10 

    Explanation: The 6th largest sum among 
    sum of all contiguous subarrays is -10.
*/
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// approach 1:
int getKthLargest(vector<int> &arr, int k){
	vector<int> sumStore;
	int n = arr.size();
	for(int i=0; i<n; i++){
		int sum = 0;
		
		for(int j=i; j<n; j++){
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}
	sort(sumStore.begin(), sumStore.end());
	return sumStore[sumStore.size()-k];
}

// approach 2:
int getKthLargest(vector<int> &arr, int k){

	priority_queue<int, vector<int>, greater<int>> min_heap;
	
	int n = arr.size();
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += arr[j];
			if(min_heap.size() < k){
				min_heap.push(sum);
			}else{
				if(sum > min_heap.top()){
					min_heap.pop();
					min_heap.push(sum);
				}
			}
		}
	}
	return min_heap.top();
}
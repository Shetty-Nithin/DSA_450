/*
Given two binary max heaps as arrays, merge the given heaps to form a 
new max heap.

Link : https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

Example 1:
    Input  : 
    n = 4 m = 3
    a[] = {10, 5, 6, 2}, 
    b[] = {12, 7, 9}

    Output : 
    {12, 10, 9, 2, 5, 7, 6}

Constraints:
    1 <= n, m <= 10^5
    1 <= a[i], b[i] <= 2*10^5

    Expected Time Complexity: O(n.Logn)
    Expected Auxiliary Space: O(n + m)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int leftNodeIndex = 2*i+1;
        int rightNodeIndex = 2*i+2;

        if(leftNodeIndex < n && arr[largest] < arr[leftNodeIndex]){
            largest = leftNodeIndex;
        }
        if(rightNodeIndex < n && arr[largest] < arr[rightNodeIndex]){
            largest = rightNodeIndex;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> result;
        
        for(auto elem:a){
            result.push_back(elem);
        }
        for(auto elem:b){
            result.push_back(elem);
        }
        
        int size = n+m;
        for(int i=size/2-1; i>=0; i--){
            heapify(result, size, i);
        }  
        
        return result;
    }
};
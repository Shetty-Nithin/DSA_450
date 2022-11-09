/*
Given an array arr[] and an integer K where K is smaller than size of 
array, the task is to find the Kth smallest element in the given array. 
It is given that all array elements are distinct.

Link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1/
Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Example 1:
    Input:
    N = 6
    arr[] = 7 10 4 3 20 15
    K = 3

    Output : 7

    Explanation :
    3rd smallest element in the given 
    array is 7.

Example 2:
    Input:
    N = 5
    arr[] = 7 10 4 20 15
    K = 4

    Output : 15

    Explanation :
    4th smallest element in the given 
    array is 15.

Constraints:
    1 <= N <= 10^5
    1 <= arr[i] <= 10^5
    1 <= K <= N

    Expected Time Complexity: O(n)
    Expected Auxiliary Space: O(log(n))
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Kth smallest
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> max_heap;
        int size = r-l+1;
        
        for(int i=0; i<k; i++){
            max_heap.push(arr[i]);
        }
        
        for(int j=k; j<size; j++){
            if(arr[j] < max_heap.top()){
                max_heap.pop();
                max_heap.push(arr[j]);
            }
        }
        
        return max_heap.top();
    }
};

// Kth largest
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthLargest(int arr[], int l, int r, int k) {
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int size = r-l+1;
        
        for(int i=0; i<k; i++){
            min_heap.push(arr[i]);
        }
        
        for(int j=k; j<size; j++){
            if(arr[j] > min_heap.top()){
                min_heap.pop();  
                min_heap.push(arr[j]);
            }
        }
        
        return min_heap.top();
    }
};

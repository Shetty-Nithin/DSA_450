/*
Find the kth max & min element of an array.
Link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

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


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//-----------------Using Heap----------------------

int kthSmallest(int arr[], int l, int r, int k) {
    
    priority_queue<int> max_heap;
    int size = r-l+1;
    
    for(int i=0; i<k; i++){
        max_heap.push(arr[i]);
    }
    
    for(int j=k; j<size; j++){
        if(max_heap.top() > arr[j]){
            max_heap.pop();
            max_heap.push(arr[j]);
        }
    }
    
    return max_heap.top();
}


//----------------Using Quick Selection---------------------------

int get_CorrectIndex(int *arr, int start, int end){
    int pivotValue = arr[end];
    int pivotIndex = start;

    for(int i=start; i<end; i++){
        if(arr[i] < pivotValue){
            swap(arr[pivotIndex], arr[i]);
            pivotIndex++;
        }
    }

    swap(arr[end], arr[pivotIndex]);
    return pivotIndex;
}

int quickSort(int *arr, int start, int end, int k){
  if(start == end){
    return arr[start];
  }
  
  int res;
  int correctPivotIndex = get_CorrectIndex(arr, start, end);

  if(correctPivotIndex == k-1){
    return arr[correctPivotIndex];
  }
  else if( correctPivotIndex < k){
    res = quickSort(arr, correctPivotIndex+1, end, k);
  }
  else{
    res = quickSort(arr, start, correctPivotIndex-1, k);
  } 
  return res;
}
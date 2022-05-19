/*
Given an array of size N. The task is to sort the array elements by 
completing functions heapify() and buildHeap() which are used to 
implement Heap Sort.

Link : https://practice.geeksforgeeks.org/problems/heap-sort/1

Example 1:
    Input:
    N = 5
    arr[] = {4,1,3,9,7}

    Output:
    1 3 4 7 9

    Explanation:
    After sorting elements
    using heap sort, elements will be
    in order as 1,3,4,7,9.

Example 2:
    Input:
    N = 10
    arr[] = {10,9,8,7,6,5,4,3,2,1}

    Output:
    1 2 3 4 5 6 7 8 9 10

    Explanation:
    After sorting elements
    using heap sort, elements will be
    in order as 1, 2,3,4,5,6,7,8,9,10.

Constraints:
    1 ≤ N ≤ 10^6
    1 ≤ arr[i] ≤ 10^6

    Expected Time Complexity: O(N * Log(N)).
    Expected Auxiliary Space: O(1).

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
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

    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2-1; i>=0; i--){
            heapify(arr, n, i);
        }
    }

    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        
        for(int i=n-1; i>=0; i--){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void print(int arr[], int n){
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Solution h;

    int arr[5] = {4, 1, 3, 9, 7};
    int n=5;

    h.heapSort(arr, n);
    h.print(arr, n);

    return 0; 
}
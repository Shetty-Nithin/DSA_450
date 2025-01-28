/*
Write a program to Cyclically rotate an array by one
Link : https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

Example 1:
    Input:
    N = 5
    A[] = {1, 2, 3, 4, 5}
    Output:
    5 1 2 3 4
 
Example 2:
    Input:
    N = 8
    A[] = {9, 8, 7, 6, 4, 2, 1, 3}
    Output:
    3 9 8 7 6 4 2 1

Constraints:
    1<=N<=10^5
    0<=a[i]<=10^5

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1
void rotate(int arr[], int n)
{
    int lastElement = arr[n-1];
    
    for(int i=n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = lastElement;
}

//approach 2
void rotate(int arr[], int n)
{
    int i = 0, j = n-1;
      while(i != j){
        swap(arr[i], arr[j]);
      i++;
    }
}
// 1, 2, 3, 4, 5
// 5, 2, 3, 4, 1
// 5, 1, 3, 4, 2
// 5, 1, 2, 4, 3
// 5, 1, 2, 3, 4

// 4, 1, 2, 3, 5
// 4, 5, 2, 3, 1
// 4, 5, 1, 3, 2
// 4, 5, 1, 2, 3

// 3, 5, 1, 2, 4
// 3, 4, 1, 2, 5
// 3, 4, 5, 2, 1
// 3 ,4 ,5, 1, 2

// 2, 4, 5 ,1, 3
// 2, 3, 5, 1, 4
// 2, 3, 4, 1, 5
// 2, 3, 4, 5, 1

// 1, 3, 4, 5, 2
// 1, 2, 4, 5, 3
// 1, 2, 3, 5, 4
// 1, 2, 3, 4, 5

void rotatebyNthTimes(int arr[], int n, int N){
    for(int i=0; i<N; i++){
        int k = 0, l = n-1;
        while(k != l){
            swap(arr[k], arr[l]);
        }
        k++;
    }
}
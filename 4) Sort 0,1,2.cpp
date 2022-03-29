/*
Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
Link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

Example 1:
    Input: 
    N = 5
    arr[]= {0 2 1 2 0}
    Output:
    0 0 1 2 2
    Explanation:
    0s 1s and 2s are segregated 
    into ascending order.

Example 2:
    Input: 
    N = 3
    arr[] = {0 1 0}
    Output:
    0 0 1
    Explanation:
    0s 1s and 2s are segregated 
    into ascending order.

Constraints:
    1 <= N <= 10^6
    0 <= A[i] <= 2

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            zeros++;
        }else if(a[i] == 1){
            ones++;
        }else{
            twos++;
        }
    }
    
    for(int i=0; i<zeros; i++){
        a[i] = 0;
    }
    for(int i=zeros; i<zeros+ones; i++){
        a[i] = 1;
    }
    for(int i=zeros+ones; i<n; i++){
        a[i] = 2;
    }
}
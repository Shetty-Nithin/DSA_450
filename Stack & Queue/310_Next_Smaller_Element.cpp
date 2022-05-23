/*
Given an array, print the Next Smaller Element (NSE) for every element. 
The NSE for an element x is the first smaller element on the right 
side of x in array. Elements for which no smaller element exist 
(on right side), consider NSE as -1. 

Link : https://www.geeksforgeeks.org/next-smaller-element/

Examples: 
a) For any array, rightmost element always has NSE as -1. 
b) For an array which is sorted in increasing order, all elements 
   have NSE as -1. 
c) For the input array [4, 8, 5, 2, 25}, the NSE for each element 
   are as follows.

Element         NSE
   4      -->    2
   8      -->    5
   5      -->    2
   2      -->   -1
   25     -->   -1

d) For the input array [13, 7, 6, 12}, the next smaller elements for 
   each element are as follows.  

  Element        NSE
   13      -->    7
   7       -->    6
   6       -->   -1
   12      -->   -1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        while(s.top() >= arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
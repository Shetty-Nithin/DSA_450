/*
The lower_bound(): 
    This method in C++ is used to return an iterator pointing to the
first element in the range [first, last) which has a value not less than val. 
This means that the function returns an iterator pointing to the next smallest 
number just greater than or equal to that number. If there are multiple values 
that are equal to val, lower_bound() returns the iterator of the first such value.
    Syntax 1: 
    ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val); 

upper_bound():
    This is a standard library function in C++ defined in the header . It 
returns an iterator pointing to the first element in the range [first, last]
that is greater than value, or last if no such element is found. The elements
in the range shall already be sorted or at least partitioned with respect to val. 


Given a sorted array arr containing n elements with possibly duplicate elements, 
the task is to find indexes of first and last occurrences of an element x in the 
given array.

Link : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Example 1:
    Input:
    n=9, x=5
    arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
    Output:  2 5
    Explanation: First occurrence of 5 is at index 2 and last
                occurrence of 5 is at index 5. 
 
Example 2:
    Input:
    n=9, x=7
    arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
    Output:  6 6 

Constraints:
    1 ≤ N ≤ 107

    Expected Time Complexity: O(logN)
    Expected Auxiliary Space: O(1).

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lower_bound(int arr[], int low, int high, int x){
    int first = -1;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == x){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] > x) 
            high = mid-1;
        else 
            low = mid+1;
    }
    return first;
}
int upper_bound(int arr[], int low, int high, int x){
    int last = -1;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == x){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] > x) 
            high = mid-1;
        else 
            low = mid+1;
    }
    return last;
}

vector<int> find(int arr[], int n , int x ){
    vector<int> ans;
    ans.push_back(lower_bound(arr, 0, n-1, x));
    ans.push_back(upper_bound(arr, 0, n-1, x));
   
    if(!ans.empty()) return ans;
    else return {-1, -1};
}
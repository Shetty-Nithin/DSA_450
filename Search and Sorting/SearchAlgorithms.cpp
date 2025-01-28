#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
1. Linear Search: 
    Time Complexity = O(n) & 
    Space Complexity = O(1)
*/
int linearSearch(vector<int> &arr, int num){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}


/*
2. Binary Search:
    Time Complexity = O(log n)
    Space Complexity = O(1)
*/
int binarySearch(vector<int> &arr, int num){
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = arr.size()-1;
    int mid;

    while(start <= end){
        mid = start + (end - start)/2;

        if(arr[mid] == num){
            return mid;
        }
        else if(mid < num){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}


/*
3. Ternary Search:
    Time Complexity = O(log3 n)
    Space Complexity = O(1)
*/
int ternarySearch(vector<int> &arr, int num){
    int start = 0;
    int end = arr.size()-1;
    int mid1, mid2;

    while(start <= end){
        mid1 = start + (end - start)/2;
        mid2 = end - (end - start)/2;

        if(arr[mid1] == num){
            return mid1;
        }
        else if(arr[mid2] == num){
            return mid2;
        }
        else if(num < mid1){
            end = mid1-1;
        }
        else if(num > mid2){
            start = mid2+1;
        }
        else{
            start = mid1+1;
            end = mid2-1;
        }
    }
    return -1;
}



/*
4. Jump Search
    Time Complexity: O(√n)
    Space Complexity: O(1)
*/
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Element not found
        }
    }

    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == target) {
            return i; // Element found at index i
        }
    }

    return -1; // Element not found
}
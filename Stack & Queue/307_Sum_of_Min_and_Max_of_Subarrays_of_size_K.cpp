/*
Given an array of both positive and negative integers, the task is to 
compute sum of minimum and maximum elements of all sub-array of size k.

Link : https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

Examples: 
    Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
            K = 4
    Output : 18
    Explanation : Subarrays of size 4 are : 
        {2, 5, -1, 7},   min + max = -1 + 7 = 6
        {5, -1, 7, -3},  min + max = -3 + 7 = 4      
        {-1, 7, -3, -1}, min + max = -3 + 7 = 4
        {7, -3, -1, -2}, min + max = -3 + 7 = 4   
        Sum of all min & max = 6 + 4 + 4 + 4 
                            = 18     
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k){

    deque<int> maxi(k);
    deque<int> mini(k);

    for(int i=0; i<k; i++){ 
        // pushigng one max element to the maxi and one min
        // element to the mini out of first k elements.
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for(int i=k; i<n ;i++){
        ans += arr[maxi.front()] + arr[mini.front()];

        while(!maxi.empty() && maxi.front() <= i-k){ // if maxi.front() index is not in the range then remove from the maxi
            maxi.pop_front();
        }

        while(!mini.empty() && mini.front() <= i-k){ // or i-mini.front() >= k
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    return ans += arr[maxi.front()] + arr[mini.front()];
}

int main(){
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}
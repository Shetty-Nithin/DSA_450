/*
You are given an array consisting of n integers which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows. You are
given the task of assigning stalls to k cows such that the minimum distance between
any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Link : https://practice.geeksforgeeks.org/problems/aggressive-cows/1

Example 1:
    Input:
        n=5 
        k=3
        stalls = [1 2 4 8 9]
    Output:
        3
    Explanation:
        The first cow can be placed at stalls[0], 
        the second cow can be placed at stalls[2] and 
        the third cow can be placed at stalls[3]. 
        The minimum distance between cows, in this case, is 3, 
        which also is the largest among all possible ways.

Example 2:
    Input:
        n=5 
        k=3
        stalls = [10 1 2 7 5]
    Output:
        4
    Explanation:
        The first cow can be placed at stalls[0],
        the second cow can be placed at stalls[1] and
        the third cow can be placed at stalls[4].
        The minimum distance between cows, in this case, is 4,
        which also is the largest among all possible ways.

Constraints:
    Expected Time Complexity: O(n*log(10^9)).
    Expected Auxiliary Space: O(1).
    
    2 <= n <= 10^5
    2 <= k <= n
    0 <= stalls[i] <= 10^9
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(int n, int k, vector<int> &stalls, int mid){
        int cows = 1;
        int lastCowPos = 0;
        for(int i=1; i<n; i++){
            if(abs(stalls[i]-stalls[lastCowPos]) >= mid){
                cows++;
                lastCowPos = i;
            }
            if(cows == k) return true;
        }
        return false;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int start = 0;
        int end = stalls[n-1]-stalls[0]; // distance between first and the last stall
        int ans = -1;
        
        int mid = start + (end-start)/2;
        while(start <= end){
           if(isPossible(n, k, stalls, mid)){
               ans = mid;
               start = mid+1;
           } 
           else end = mid-1;
           mid = start + (end-start)/2;
        }
        return ans;
    }
};
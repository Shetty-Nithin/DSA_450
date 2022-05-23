/*
Given an array A[] of size N and a positive integer K, find the first 
negative integer for each and every window(contiguous subarray) of size K.

Example 1:
    Input : 
    N = 5
    A[] = {-8, 2, 3, -6, 10}
    K = 2
    Output : 
    -8 0 -6 -6
    Explanation :
    First negative integer for each window of size k
    {-8, 2} = -8
    {2, 3} = 0 (does not contain a negative integer)
    {3, -6} = -6
    {-6, 10} = -6
 
Example 2:
    Input : 
    N = 8
    A[] = {12, -1, -7, 8, -15, 30, 16, 28}
    K = 3
    Output :
    -1 -1 -7 -15 -15 0 

Constraints:
    1 <= N <= 10^5
    -105 <= A[i] <= 10^5
    1 <= K <= N

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(K)


*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    for(int i=0; i<K; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }

    for(int i=K; i<N; i++){
        if(!dq.empty() && i-dq.front() >= K){
            dq.pop_front();
        }
        
        if(A[i] < 0){
            dq.push_back(i);
        }
        
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }

    return ans;
 }
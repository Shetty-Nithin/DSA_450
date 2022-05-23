/*
Find Largest sum contiguous Subarray [Kadane's Algorithm]
Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

Example 1:
    Input:
    N = 5
    Arr[] = {1,2,3,-2,5}
    Output:
    9
    Explanation:
    Max subarray sum is 9
    of elements (1, 2, 3, -2, 5) which 
    is a contiguous subarray.

Example 2:
    Input:
    N = 4
    Arr[] = {-1,-2,-3,-4}
    Output:
    -1
    Explanation:
    Max subarray sum is -1 
    of element (-1)

Constraints:
    1 ≤ N ≤ 10^6
    -107 ≤ A[i] ≤ 10^7

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    
    long long ans = INT_MIN;
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        ans = max(ans, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return ans;
}

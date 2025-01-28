/*
Minimize the Heights II
Link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

Example 1:
    Input:
    K = 2, N = 4
    Arr[] = {1, 5, 8, 10}
    Output:
    5
    Explanation:
    The array can be modified as
    {3, 3, 6, 8}. The difference between
    the largest and the smallest is 8-3 = 5.

Example 2:
    Input:
    K = 3, N = 5
    Arr[] = {3, 9, 12, 16, 20}
    Output:
    11
    Explanation:
    The array can be modified as
    {6, 12, 9, 13, 17}. The difference between
    the largest and the smallest is 17-6 = 11.

Constraints:
    1 ≤ K ≤ 10^4
    1 ≤ N ≤ 10^5
    1 ≤ Arr[i] ≤ 10^5

    Expected Time Complexity: O(N*logN)
    Expected Auxiliary Space: O(N)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int mini = arr[0]; // these are initial maximum, minimum and the difference.
        int maxi = arr[n - 1];
        int diff = maxi - mini;

        // update maxi, mini and diff
        for (int i = 1; i < n; i++)
        { // range from second number to last-1
            if (arr[i] - k < 0)
            {
                continue;
            }
            mini = min(arr[0]+k, arr[i]-k);
            maxi = max(arr[i-1]+k, arr[n-1]-k);
            diff = min(diff, maxi - mini);
        }

        return diff;
    }
};
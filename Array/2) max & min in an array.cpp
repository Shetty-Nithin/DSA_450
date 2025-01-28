/*
Maximum and minimum of an array using minimum number of comparisons.
Link : https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

Example 1:
    Input:
    N = 6
    A[] = {3, 2, 1, 56, 10000, 167}
    Output:
    min = 1, max =  10000

Example 2:
    Input:
    N = 5
    A[]  = {1, 345, 234, 21, 56789}
    Output:
    min = 1, max = 56789

Constraints:
    1 <= N <= 10^5
    1 <= Ai <=10^12

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int n)
{
    long long mini = a[0];
    long long maxi = a[0];

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
    }
    pair<long long, long long> p = make_pair(mini, maxi);

    return p;
}


/*
Similar Problem:
Removing minimum and maximum from an array
Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/
*/
class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int minPosition = 0;
        int maxPosition = 0;
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        int totalRemoval = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minValue)
            {
                minValue = nums[i];
                minPosition = i;
            }
            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxPosition = i;
            }
        }

        if (minPosition < maxPosition)
        {
            int leftRight = (minPosition + 1) + (nums.size() - maxPosition);
            int leftLeft = maxPosition + 1;
            int rightRight = nums.size() - minPosition;
            totalRemoval = min(leftRight, min(leftLeft, rightRight));
        }
        else
        {
            int leftRight = (maxPosition + 1) + (nums.size() - minPosition);
            int leftLeft = minPosition + 1;
            int rightRight = nums.size() - maxPosition;
            totalRemoval = min(leftRight, min(leftLeft, rightRight));
        }

        return totalRemoval;
    }
};
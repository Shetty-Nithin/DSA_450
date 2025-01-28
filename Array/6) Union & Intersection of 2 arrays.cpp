/*
Find Union and Intersection of two unsorted arrays.
Link : https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

Example 1:
    Input:
    5 3
    1 2 3 4 5
    1 2 3
    Output: 
    5
    Explanation: 
    1, 2, 3, 4 and 5 are the
    elements which comes in the union set
    of both arrays. So count is 5.

Example 2:
    Input:
    6 2 
    85 25 1 32 54 6
    85 2 
    Output: 
    7
    Explanation: 
    85, 25, 1, 32, 54, 6, and
    2 are the elements which comes in the
    union set of both arrays. So count is 7.

Constraints:
    1 ≤ n, m ≤ 10^5
    0 ≤ a[i], b[i] < 10^5

    Expected Time Complexity : O((n+m)log(n+m))
    Expected Auxilliary Space : O(n+m)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    set<int> ans;
    
    for(int i=0; i<n; i++){
        ans.insert(a[i]);
    }
    for(int j=0; j<m; j++){
        ans.insert(b[j]);
    }
    
    return ans.size();
}

//To find intersection of 2 sets, we can use 2 <set>. First <set> is for storing all the different element from first set.
//and second set is for storing all the intersection elements.

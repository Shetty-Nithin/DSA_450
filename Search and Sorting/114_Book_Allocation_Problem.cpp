/*
You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contiguous books to M number of students. There can
be many ways or permutations to do so. In each permutation, one of the M
students will be allocated the maximum number of pages. Out of all these
permutations, the task is to find that particular permutation in which the
maximum number of pages allocated to a student is the minimum of those in
all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to 
be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should 
be in contiguous order (see the explanation for better understanding).

Link : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
Link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

Example 1:
    Input:
        N = 4
        A[] = {12,34,67,90}
        M = 2
    Output:113
    Explanation:Allocation can be done in 
        following ways:
        {12} and {34, 67, 90} Maximum Pages = 191
        {12, 34} and {67, 90} Maximum Pages = 157
        {12, 34, 67} and {90} Maximum Pages =113.
        Therefore, the minimum of these cases is 113,
        which is selected as the output.

Example 2:
    Input:
        N = 3
        A[] = {15,17,20}
        M = 2
    Output:32
    Explanation: Allocation is done as
        {15,17} and {20}

Constraints:
    Expected Time Complexity: O(NlogN)
    Expected Auxilliary Space: O(1)
    
    1 <= N <= 10^5
    1 <= A [ i ] <= 10^6
    1 <= M <= 10^5
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool isPossible(int A[], int N, int M, int mid){
        int tempM = 1;
        int currPageSum = 0;
        for(int i=0; i<N; i++){
            if(currPageSum+A[i] <= mid){
                currPageSum += A[i];
            }
            else{
                tempM++;
                if(tempM > M || A[i] > mid){
                    return false;
                }
                currPageSum = A[i];
            }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) {
        if(M > N) return -1;
        int ans = -1;
        int start = 0;
        int end = 0;
        
        for(int i=0; i<N; i++){
            end += A[i];
        }

        int mid = start + (end-start)/2;
        while(start <= end){
            if(isPossible(A, N, M, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    int A[] = {12, 34, 67, 90};
    cout << s.findPages(A, 4, 5);
}
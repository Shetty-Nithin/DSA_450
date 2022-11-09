/*
Given K sorted lists of integers, KSortedArray[] of size N each. 
The task is to find the smallest range that includes at least one 
element from each of the K lists. If more than one such range's are 
found, return the first such range found.

Link : https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
Link : https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356
Link : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

Example 1:
    Input:
    N = 5, K = 3
    KSortedArray[][] = {{1 3 5 7 9},
                        {0 2 4 6 8},
                        {2 3 5 7 11}}
    Output: 1 2

    Explanation: K = 3
    A:[1 3 5 7 9]
    B:[0 2 4 6 8]
    C:[2 3 5 7 11]
    Smallest range is formed by number 1
    present in first list and 2 is present
    in both 2nd and 3rd list.

Example 2:
    Input:
    N = 4, K = 3
    KSortedArray[][] = {{1 2 3 4},
                        {5 6 7 8},
                        {9 10 11 12}}
    Output: 4 9

Constraints:
    1 <= K,N <= 500
    0 <= a[ i ] <= 10^5

    Expected Time Complexity : O(n * k *log k)
    Expected Auxilliary Space  : O(k)
*/

#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

class Node {
	public:
	int data;
	int row;
	int col;
	
	Node(int d, int r, int c){
		data = d;
		row = r;
		col = c;
	}
};

class compare {
	public:
	bool operator()(Node* a, Node* b){
		return a->data > b->data;
	}
};

class Solution {
    public:
    int kSorted(vector<vector<int>> &a, int k, int n) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        priority_queue<Node*, vector<Node*>, compare > min_heap;
        
        for(int i=0; i<k; i++){
            int element = a[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            min_heap.push(new Node(element, i, 0));
        }
        
        int start = mini;
        int end = maxi;
        while(!min_heap.empty()){
            Node* temp = min_heap.top();
            min_heap.pop();
            mini = temp->data;
            
            if((maxi-mini) < (end-start)){
                start = mini;
                end = maxi;
            }
            if(temp->col+1 < n){
                maxi = max(maxi, a[temp->row][temp->col+1]);
                min_heap.push(new Node(a[temp->row][temp->col+1], temp->row, temp->col+1));
            }else{
                break;
            }
        }
        return (end-start+1);
    }
};
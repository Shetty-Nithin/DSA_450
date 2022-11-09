/*
Given a BST and an integer K. Find the Kth Smallest element in the BST.
Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

Example 1:
    Input:
       2
     /   \
    1     3
    K = 2
    Output: 2

Example 2:
    Input:
      2
     /  \
    1    3
    K = 5
    Output: -1
 
Constraints:
    1<=Number of nodes<=100000

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).

*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int solve(Node* root, int k, int &count){
        if(root == NULL){
            return -1;
        }
        
        int left = solve(root->left, k, count);
        
        if(left != -1){
            return left;
        }
        
        count++;
        if(k == count){
            return root->data;
        }
        
        return solve(root->right, k, count);
    }
    int KthSmallestElement(Node *root, int K) {
        int count = 0;
        int ans = solve(root, K, count);
        return ans;
    }
};
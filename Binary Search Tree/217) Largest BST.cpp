/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.
Link : https://practice.geeksforgeeks.org/problems/largest-bst/1#

Example 1:
    Input:
          1
        /   \
       4     4
     /   \
    6     8
    Output: 1
    Explanation: There's no sub-tree with size
    greater than 1 which forms a BST. All the
    leaf Nodes are the BSTs with size equal
    to 1.

Example 2:
    Input: 6 6 3 N 2 9 3 N 8 8 2
              6
           /     \
         6         3
          \      /   \
           2    9     3
            \  /  \
            8 8    2 
    Output: 2
    Explanation: The following sub-tree is a
    BST of size 2: 
        2
     /    \ 
    N      8


Constraints:
    1 ≤ Number of nodes ≤ 10^5
    1 ≤ Data of a node ≤ 10^6

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the BST).
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

class info {
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
};

class Solution{
    public:
    info solve(Node* root, int &maxSize){
        if(root == NULL){
            return {INT_MAX, INT_MIN, true, 0}; // (mini, maxi, isBST, size)
        }
        
        info left = solve(root->left, maxSize);
        info right = solve(root->right, maxSize);
        
        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
        
        if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
            currNode.isBST = true;
        }else{
            currNode.isBST = false;
        }
         
        if(currNode.isBST){
            maxSize = max(maxSize, currNode.size);
        }
        
        return currNode;
    }
    
    int largestBst(Node *root){
    	int maxSize = 0;
    	solve(root, maxSize);
    	return maxSize;
    }
};
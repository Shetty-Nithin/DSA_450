/*
Given a binary tree. The task is to check whether the given tree follows 
the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of 
      node greater than or equal to its child.

Link : https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

Example 1:
    Input:
          5
         /  \
        2    3
    Output: 1
    Explanation: The given tree follows max-heap property since 5,
    is root and it is greater than both its children.

Example 2:
    Input:
          10
         /   \
        20   30 
       /   \
      40   60
    Output: 0


Constraints:
    1 ≤ Number of nodes ≤ 100
    1 ≤ Data of a node ≤ 1000

    Expected Time Complexity: O(N)
    Expected Space Complexity: O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Structure of node
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
    int countNodes(struct Node* root){
        if(root == NULL){
            return 0;
        }
        
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root, int index, int totalCount){
        if(root == NULL){
            return true;
        }
        
        if(index >= totalCount){
            return false;
        }else{                 // node  &  its position
            bool left = isCBT(root->left, 2*index+1, totalCount);
            bool right = isCBT(root->right, 2*index+2, totalCount);
            
            return (left && right);
        }
    }
    
    bool isMaxOrder(struct Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        if(root->right == NULL){
            return (root->data > root->left->data);
        }else{ // root->right is not checking because, itis already verified in isCBT. (no such combination with left = null and right != null)
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return (left && right && ((root->data > root->left->data) && (root->data > root->right->data)));
        }
    }

    bool isHeap(struct Node* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root, index, totalCount) && isMaxOrder(root)){
            return true;
        }else{
            return false;
        }
    }
};

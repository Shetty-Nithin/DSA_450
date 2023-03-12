/*
Given a Binary Search Tree (with all values unique) and two node values.
Find the Lowest Common Ancestors of the two nodes in the BST.
Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

Example 1:
    Input:
              5
            /    \
           4      6
         /         \
        3           7
                     \
                      8
    n1 = 7, n2 = 8
    Output: 7

Example 2:
    Input:
       2
     /   \
    1     3
    n1 = 1, n2 = 3
    Output: 2

Constraints:
    1 <= N <= 10^4

    Expected Time Complexity: O(Height of the BST).
    Expected Auxiliary Space: O(Height of the BST).
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};


//Recursion
Node* LCA(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data > n1 && root->data > n2){
        return LCA(root->left, n1, n2);
    }
    if(root->data < n1 && root->data < n2){
        return LCA(root->right, n1, n2);
    }
    
    return root;
}

//Iterative
Node* LCA(Node *root, int n1, int n2){
   if(root == NULL){
       return NULL;
   }
   
   while(root != NULL){
       if(root->data > n1 && root->data > n2){
           root = root->left;
       }
       else if(root->data < n1 && root->data < n2){
           root = root->right;
       }else{
           return root;
       }
   }
}
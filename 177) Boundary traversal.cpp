/*
Boundary Traversal of binary tree.
Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

Example 1:
    Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
    Output: 1 2 4 8 9 6 7 3

Example 2:
    Input:
            1
           / 
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

    Output: 1 2 4 6 5 7 8

Constraints:
    1 ≤ Number of nodes ≤ 10^5
    1 ≤ Data of a node ≤ 10^5

    Expected Time Complexity: O(N). 
    Expected Auxiliary Space: O(Height of the Tree).
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right){
            traverseRight(root->right, ans);
        }else{
            traverseRight(root->left, ans);
        }
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        traverseLeft(root->left, ans);
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        traverseRight(root->right, ans);
        
        return ans;
    }
};
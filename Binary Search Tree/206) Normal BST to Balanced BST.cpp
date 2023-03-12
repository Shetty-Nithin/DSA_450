/*
Given a BST (Binary Search Tree) that may be unbalanced, convert it
into a balanced BST that has minimum possible height.
Link : https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1/
Link : https://leetcode.com/problems/balance-a-binary-search-tree/description/

Examples 1:
    Input:
        30
        /
      20
      /
    10
    Output:
       20
      /   \
    10     30

Examples 2:
    Input:
          4
         /
        3
       /
      2
     /
    1
    Output:
         3            3           2
        /  \         /  \        /  \
       1    4   OR  2    4  OR  1    3   OR ..
        \          /                   \
         2        1                     4 




Constraints:
    1<=N<=200

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node(int val){
      this->data = val;
      this->left = NULL;
      this->right = NULL;
    }
}; 

void inOrder(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

Node* inOrderToBST(int start, int end, vector<int> &v){
    if(start > end){
        return NULL;
    }
    
    int mid = (start + end)/2;
    Node* root = new Node(mid);
    root->left = inOrderToBST(start, mid-1, v);
    root->right = inOrderToBST(mid+1, end, v);
    
    return root;
    
}
Node* buildBalancedTree(Node* root){
	vector<int> v;
	inOrder(root, v);
	
	return inOrderToBST(0, v.size()-1, v);
}


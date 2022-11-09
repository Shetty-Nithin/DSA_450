/*
Given a binary search tree, the task is to flatten it to a sorted list.
Precisely, the value of each node must be lesser than the values of all
the nodes at its right, and its left node must be NULL after flattening.
We must do it in O(H) extra space where ‘H’ is the height of BST.

Link : https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/
Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/

Examples 1: 
    Input: 
            5 
          /   \ 
         3     7 
        / \   / \ 
       2   4 6   8
    Output: 2 3 4 5 6 7 8

Examples 2: 
    Input:
        1
         \
          2
           \
            3
             \
              4
               \
                5
    Output: 1 2 3 4 5

Constraints:
    Time Complexity: O(N)
    Auxiliary Space: O(N)
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

void inOrder(Node* root, vector<Node*> &v){
    if(root == NULL){
        return;
    }

    inOrder(root->left, v);
    v.push_back(root);
    inOrder(root->right, v);
}

Node* flatten(Node* root){
    vector<Node*> v;
    inOrder(root, v);

    Node* newRoot = new Node(v[0]->data);
    Node* curr = newRoot;

    for(int i=1; i<v.size(); i++){
        Node* temp = new Node(v[i]->data);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

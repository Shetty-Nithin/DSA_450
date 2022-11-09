/*
Given a binary search tree which is also a complete binary tree. The 
problem is to convert the given BST into a Min Heap with the condition 
that all the values in the left subtree of a node should be less than 
all the values in the right subtree of the node. This condition is 
applied on all the nodes in the so converted Min Heap.

Link :  https://www.geeksforgeeks.org/convert-bst-min-heap/

Examples 1:
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

The given BST has been transformed into a Min Heap.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
public:
    void inorderTraversal(Node* root, vector<int>& arr){
        if (root == NULL){
            return;
        }

        inorderTraversal(root->left, arr);
        arr.push_back(root->data);
        inorderTraversal(root->right, arr);
    }

    Node* BSTToMinHeap(Node* root, vector<int> arr, int* i){
        if (root == NULL){
            return NULL;
        }

        root->data = arr[++*i];
        root->left = BSTToMinHeap(root->left, arr, i);
        root->right = BSTToMinHeap(root->right, arr, i);

        return root;
    }

    Node* convertToMinHeapUtil(Node* root){
        vector<int> arr;
        int i = -1;
    
        inorderTraversal(root, arr);
        return BSTToMinHeap(root, arr, &i);
    }

    void preorderTraversal(Node* root, vector<int> &output){
        if (!root) return;
    
        output.push_back(root->data);
        preorderTraversal(root->left, output);
        preorderTraversal(root->right, output);
    }

    vector<int> bstToMInHeap(Node* root){
        vector<int> output;
        root = convertToMinHeapUtil(root);
        preorderTraversal(root, output);

        for(auto i : output){
            cout << i << ", ";
        }cout << endl;
        
        return output;
    }
};

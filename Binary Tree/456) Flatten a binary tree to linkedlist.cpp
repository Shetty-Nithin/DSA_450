/*
Given a binary tree, flatten it into linked list in-place. Usage of 
auxiliary data structure is not allowed. After flattening, left of 
each node should point to NULL and right should contain next node in
preorder.
Link : https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

Example 1:
    Input : 
              1
            /   \
           2     5
          / \     \
         3   4     6
    Output :
    1 2 3 4 5 6 
    Explanation: 
    After flattening, the tree looks 
    like this
        1
         \
          2
           \
            3
             \
              4
               \
                5
                 \
                  6 
    Here, left of each node points 
    to NULL and right contains the 
    next node in preorder.The inorder 
    traversal of this flattened tree 
    is 1 2 3 4 5 6.

Example 2:
    Input :
            1
           / \
          3   4
             /
            2
            \
             5 
    Output : 
    1 3 4 2 5  
    Explanation : 
    After flattening, the tree looks 
    like this 
        1
         \
          3
           \
            4
             \
              2
               \ 
                5 
    Here, left of each node points 
    to NULL and right contains the 
    next node in preorder.The inorder 
    traversal of this flattened tree 
    is 1 3 4 2 5.

 
Constraints :
    1<=n<=10^5

    Expected Time Complexity: O(n)
    Expected Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr){
            if(curr->left == NULL){
                curr = curr->right;
            }else{
                Node* pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        }
    }
};
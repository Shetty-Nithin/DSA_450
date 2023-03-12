/*
Given a binary tree. Find the inorder traversal of the tree without 
using recursion.
Link : https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU

Example 1
    Input:
              1
            /    \
           2      3
         /   \
        4     5
    Output: 4 2 5 1 3
    Explanation:
    Inorder traversal (Left->Root->Right) of 
    the tree is 4 2 5 1 3.

Example 2
    Input:
                 8
              /     \
             1       5
              \     /  \
               7   10   6
                \  /
                10 6
    Output: 1 7 10 8 6 10 5 6
    Explanation:
    Inorder traversal (Left->Root->Right) 
    of the tree is 1 7 10 8 6 10 5 6.


Constraints:
    1 <= Number of nodes <= 10^5
    1 <= Data of a node <= 10^5

    Expected time complexity: O(N)
    Expected auxiliary space: O(N)
*/

// without using space for queue

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector<int> inOrder(Node* root){
        vector<int> ans;
        Node* curr = root;
        
        while(curr){
            if(curr->left == NULL){
                // Left, Node, Right
                ans.push_back(curr->data);
                curr = curr->right;
            }else{
                Node* pred = curr->left; //predeccesor
                while(pred->right && pred->right != curr){ // 2nd condition : Right most node is NOT already linked to it curr node.
                    pred = pred->right;
                }
                // this executes on the first time
                if(pred->right == NULL){
                    pred->right = curr; // link the right most node to the curr node.
                    curr = curr->left; // go for next node
                }else{
                    // this executes on the 2nd time
                    ans.push_back(curr->data);
                    pred->right = NULL; // breaking the link to avoid the infinite loop
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
/*
Given a binary tree, find its preorder traversal.
Link : https://practice.geeksforgeeks.org/problems/preorder-traversal/1#

Example 1:
    Input:
            1      
          /          
        4    
      /    \   
    4       2
    Output: 1 4 4 2 

Example 2:
    Input:
          6
        /   \
       3     2
        \   / 
         1 2
    Output: 6 3 1 2 2 


Constraints:
    1 <= Number of nodes <= 10^4
    0 <= Data of a node <= 10^5

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector <int> preorder(Node* root){
    vector<int> ans;
    Node* curr = root;
    
    while(curr){
        ans.push_back(curr->data);
        
        if(curr->left == NULL){
            curr = curr->right;
        }else{
            Node* succ = curr->left;
            while(succ->right && succ->right != curr){ // 2nd condition : we can use "succ->right != curr->right" (this makes more sence).
                succ = succ->right;
            }
            if(succ->right == NULL){
                succ->right = curr->right;
                curr = curr->left;
            }
        }
    }
    return ans; 
}
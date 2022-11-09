/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
Link : https://practice.geeksforgeeks.org/problems/check-for-bst/1#

Example 1:
    Input:
       2
     /   \
    1     3
    Output: 1 
    Explanation: 
    The left subtree of root node contains node
    with key lesser than the root nodes key and 
    the right subtree of root node contains node 
    with key greater than the root nodes key.
    Hence, the tree is a BST.

Example 2:
    Input:
    2
     \
      7
       \
        6
         \
          5
           \
            9
             \
              2
               \
                6
    Output: 0 
    Explanation: 
    Since the node with value 7 has right subtree 
    nodes with keys less than 7, this is not a BST.

Constraints:
    0 <= Number of edges <= 100000

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the BST).
*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    
    bool isBST(Node* root, int mini, int maxi){
        if(root == NULL){
            return true;
        }
        
        if(root->data > mini && root->data < maxi){
            bool left = isBST(root->left, mini, root->data);
            bool right = isBST(root->right, root->data, maxi);
            
            return left&&right;
        }else{
            return false;
        }
    }
    bool isBST(Node* root) 
    {
        return isBST(root, INT_MIN, INT_MAX);
    }
};


// Approach 2 : 
class Solution{
    private:
        void inOrder(Node* root, vector<int> &in){
            if(root == NULL) return;
            
            inOrder(root->left, in);
            in.push_back(root->data);
            inOrder(root->right, in);
        }

    public:
    bool isBST(Node* root) 
    {
        vector<int> in;
        inOrder(root, in);
        
        for(int i=0; i<in.size()-1; i++){
            if(in[i] > in[i+1]){
                return false;
            }
        }
        return true;
    }
};
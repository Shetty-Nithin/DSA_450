/*
Given a binary tree of size N, find its reverse level order traversal.
Link : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#
Link : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

Example 1:
    Input :
          1
        /   \
       3     2

    Output: 3 2 1

Example 2:
    Input :
           10
          /  \
         20   30
        / \ 
       40  60
    Output: 40 60 20 30 10



Constraints:
    1 ≤ N ≤ 10^4
    
    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    vector<int> arr;

    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        
        arr.push_back(temp->data);
    }
    
    int i=0;
    int j=arr.size()-1;
    while(i<j){
       swap(arr[i], arr[j]);
       i++;
       j--;
    }
    return arr;
}


// LeetCode Problem : slight variation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level_order_Reverse;
        queue<TreeNode*> q;
        
        if(root == NULL) return level_order_Reverse;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            vector<int> curr_level;
            
            while(temp){
                curr_level.push_back(temp->val); 
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
                temp = q.front();
                q.pop();
            }
            if(!q.empty()){
                q.push(NULL);
            }
            
            level_order_Reverse.push_back(curr_level);

        }
        
        reverse(level_order_Reverse.begin(), level_order_Reverse.end());
        return level_order_Reverse;
    }
};
/*
Given a binary tree, find if it is height balanced or not.
Link : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1


Example 1:
    Input:
        1
        /
    2
        \
        3 
    Output: 0
    Explanation: The max difference in height
    of left subtree and right subtree is 2,
    which is greater than 1. Hence unbalanced

Example 2:
    Input:
        10
        /   \
        20   30 
    /   \
    40   60
    Output: 1
    Explanation: The max difference in height
    of left subtree and right subtree is 1.
    Hence balanced.

Constraints:
    1 <= Number of nodes <= 10^5
    0 <= Data of a node <= 10^6

    Expected time complexity: O(N)
    Expected auxiliary space: O(h) , where h = height of tree
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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

pair<bool, int> balancedCheck(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    pair<bool, int> left = balancedCheck(root->left);
    pair<bool, int> right = balancedCheck(root->right);
    
    pair<bool, int> ans;
    bool diff = abs(left.second - right.second) <= 1;
    if(left.first && right.first && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    ans.second = max(left.second, right.second)+1;
    
    return ans;
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    return balancedCheck(root).first;
}
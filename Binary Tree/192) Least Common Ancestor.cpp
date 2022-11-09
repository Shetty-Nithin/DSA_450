/*
Lowest Common Ancestor in a Binary Tree.
Given a Binary Tree with all unique values and two nodes value, n1 and n2.
The task is to find the lowest common ancestor of the given two nodes.
We may assume that either both n1 and n2 are present in the tree or none of them are present.
Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Example 1:
    Input:
    n1 = 2 , n2 = 3  
         1 
        / \ 
       2   3
    Output: 1
    Explanation:
    LCA of 2 and 3 is 1.

Example 2:
    Input:
    n1 = 3 , n2 = 4
             5    
            /    
           2  
          / \  
         3   4
    Output: 2
    Explanation:
    LCA of 3 and 4 is 2.

Constraints:
    1 ≤ Number of nodes ≤ 10^5
    1 ≤ Data of a node ≤ 10^5

    Expected Time Complexity:O(N).
    Expected Auxiliary Space:O(Height of Tree).
*/

#include<bits/stdc++.h>
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

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root == NULL){
        return NULL;
    }
    if(n1 == root->data || n2 == root->data){
        return root;
    }
    
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    
    if(left != NULL && right != NULL){
        return root;
    }else if(left != NULL && right == NULL){
        return left;
    }else if(left == NULL && right != NULL){
        return right;
    }else{
        return NULL;
    }
}

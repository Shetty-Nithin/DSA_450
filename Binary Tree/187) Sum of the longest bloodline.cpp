/*
Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node).
Link : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

Example 1:
    Input: 
            4        
           / \       
          2   5      
         / \ / \     
        7  1 2  3    
          /
         6
    Output: 13
    Explanation:
            4        
           / \       
          2   5      
         / \ / \     
        7  1 2  3 
          /
         6

    The highlighted nodes (4, 2, 1, 6) above are 
    part of the longest root to leaf path having
    sum = (4 + 2 + 1 + 6) = 13

Example 2:
    Input: 
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    Output: 11


Constraints:
    1 <= Number of nodes <= 10^4
    1 <= Data of a node <= 10^4

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root, pair<int, int> &ans, int currPathLen, int currPathSum){
    if(root == NULL){
        if(currPathLen >= ans.second){
            if(currPathLen == ans.second){
                ans.first = max(ans.first, currPathSum);
            }else{
                ans.first = currPathSum;
                ans.second = currPathLen;
            }
        }
        return;
    }
    currPathSum = currPathSum + root->data;
    currPathLen++;
    
    solve(root->left, ans, currPathLen, currPathSum);
    solve(root->right, ans, currPathLen, currPathSum);
}
int sumOfLongRootToLeafPath(Node *root){
    pair<int, int> ans = make_pair(0, 0); // (currPathSum, currPathLen)
    int currPathSum = 0;
    int currPathLen = 0;
    
    if(root == NULL){
        return currPathSum;
    }
    solve(root, ans, currPathLen, currPathSum);
    
    return ans.first;
}
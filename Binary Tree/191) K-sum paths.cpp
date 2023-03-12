/*
Print all k-sum paths in a binary tree.
Given a binary tree and an integer K. Find the number of paths in the tree
which have their sum equal to K. A path may start from any node and end at
any node in the downward direction.
Link : https://practice.geeksforgeeks.org/problems/k-sum-paths/1/
Link : https://leetcode.com/problems/path-sum-iii/description/

Example 1:
    Input:      
    Tree = 
              1                               
            /   \                          
           2     3
    K = 3
    Output: 2
    Explanation:
    Path 1 : 1 + 2 = 3
    Path 2 : only leaf node 3

Example 2:
    Input: 
    Tree = 
                1
             /    \
           3        -1
         /   \     /   \
        2     1   4     5                        
             /   / \     \                    
            1   1   2     6    
    K = 5                    
    Output: 8
    Explanation:
    The following paths sum to K.  
    3 2 
    3 1 1 
    1 3 1 
    4 1 
    1 -1 4 1 
    -1 4 2 
    5 
    1 -1 5 

Constraints:
    1 ≤ N ≤ 10^5
    -105 ≤ Node Value ≤ 10^5
    -109 ≤ k ≤ 10^9

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(Height of Tree)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//                            vector<int> &path
void solve(Node* root, int k, vector<int> path, int &count){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    
    solve(root->left, k, path, count);
    solve(root->right, k, path, count);
    
    int size = path.size();
    int sum = 0;
    for(int i=size-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
    // path.pop_back(); // is not required
}

int sumK(Node *root,int k){
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    
    return count;
}


// Leetcode: 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    // Go down completely till the NULL node and push all the node you encounter. 
    // Once the node is null, then use for loop to check targetSum in the currPath array. 
    // Once the for loop exists, just pop out the last node and push another node.
    void findTotalPaths(TreeNode* root, int targetSum, int &totalPath, vector<int> &currPath){
        if(root == NULL){
            return;
        }

        currPath.push_back(root->val);
        findTotalPaths(root->left, targetSum, totalPath, currPath);
        findTotalPaths(root->right, targetSum, totalPath, currPath);

        int size = currPath.size();
        long long tempSum = 0;
        for(int i=size-1; i>=0; i--){
            tempSum += currPath[i];
            if(tempSum == targetSum){
                totalPath++;
            }
        }
        currPath.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int totalPath = 0;
        vector<int> currPath;

        findTotalPaths(root, targetSum, totalPath, currPath);
        return totalPath;
    }
};
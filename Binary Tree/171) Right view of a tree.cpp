/*
Given a Binary Tree, find Right view of it.
Link : https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

Example 1:
    Input:
          1
        /    \
       3      2
    Output: 1 2

Example 2:
    Input:
         10
        /   \
      20     30
     /   \
    40  60 
    Output: 10 30 60

Constraints:
    1 ≤ Number of nodes ≤ 105
    1 ≤ Data of a node ≤ 105

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the Tree).
*/

#include<bits/stdc++.h>
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
//--------------------------Iterative way------------------------------
vector<int> rightView(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    map<int, int> m;
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* rightNode = temp.first;
        int level = temp.second;
        
        m[level] = rightNode->data;
        
        if(rightNode->left){
            q.push(make_pair(rightNode->left, level+1));
        }
        if(rightNode->right){
            q.push(make_pair(rightNode->right, level+1));
        }
    }
    for(auto elem : m){
        ans.push_back(elem.second);
    }
    
    return ans;
}

//-------------------------Recursive way-----------------------
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    
    return ans;
}
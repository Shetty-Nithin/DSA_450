/*
Given a binary tree, print the bottom view from left to right.
Link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

Example 1:
    Input:
       1
     /   \
    3     2
    Output: 3 1 2

Example 2:
    Input:
         10
       /    \
      20    30
     /  \
    40   60
    Output: 40 20 60 30


Constraints:
    1 <= Number of nodes <= 105
    1 <= Data of a node <= 105

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector <int> bottomView(Node *root) {
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
        
        Node* bottomNode = temp.first;
        int hd = temp.second;
        
        m[hd] = bottomNode->data;
        
        if(bottomNode->left){
            q.push(make_pair(bottomNode->left, hd-1));
        }
        if(bottomNode->right){
            q.push(make_pair(bottomNode->right, hd+1));
        }
    }
    for(auto elem : m){
        ans.push_back(elem.second);
    }
    return ans;
}
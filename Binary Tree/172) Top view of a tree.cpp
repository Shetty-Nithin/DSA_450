/*
Given below is a binary tree. The task is to print the top view of binary tree.
Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Example 1:
    Input:
      1
   /    \
  2      3
    Output: 2 1 3

Example 2:
    Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
    Output: 40 20 10 30 100

Constraints:
    1 ≤ N ≤ 105
    1 ≤ Node Data ≤ 105

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node *root){
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
        
        Node* topNode = temp.first;
        int hd = temp.second;
        
        if(m.find(hd) == m.end()){
            m[hd] = topNode->data;
        }
        
        if(topNode->left){
            q.push(make_pair(topNode->left, hd-1));
        }
        if(topNode->right){
            q.push(make_pair(topNode->right, hd+1));
        }
    }
    for(auto elem : m){
        ans.push_back(elem.second);
    }
    return ans;
}
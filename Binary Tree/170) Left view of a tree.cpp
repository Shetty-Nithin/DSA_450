/*
Given a Binary Tree, print Left view of it.
Link : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Example 1:
    Input:
     1
    /  \
   3    2
    Output: 1 3

Example 2:
    Input:
        10
       /  \
     20   30
    /   \
   40  60
    Output: 10 20 40


Constraints:
    0 <= Number of nodes <= 100
    1 <= Data of a node <= 1000

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

//----------------------------Iterative way---------------------
vector<int> leftView(Node *root){
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   
   map<int, int> m;
   queue<pair<Node*, int>> q;
   // Node* => node &
   // int => level (vertically)
   
   q.push(make_pair(root, 0));
   while(!q.empty()){
       pair<Node*, int> temp = q.front();
       q.pop();
       
       Node* leftNode = temp.first;
       int level = temp.second;
       
       if(m.find(level) == m.end()){
           m[level] = leftNode->data;
       }
       
       if(leftNode->left){
           q.push(make_pair(leftNode->left, level+1));
       }
       if(leftNode->right){
           q.push(make_pair(leftNode->right, level+1));
       }
   }
   for(auto elem : m){
       ans.push_back(elem.second);
   }
   
   return ans;
}

//-----------------------Recursive way------------------------------
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // all the left node will be pushed the recurssive heap and
    // the size of the stack will be same as the level of the BT.
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node *root){
    vector<int> ans;
    solve(root, ans, 0);
    
    return ans;
}
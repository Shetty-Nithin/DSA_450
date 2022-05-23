/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.
Link : https://practice.geeksforgeeks.org/problems/level-order-traversal/1# 

Example 1:
    Input:
          1
        /   \ 
       3     2
    Output: 1 3 2

Example 2:
    Input:
               10
             /    \
           20     30
        /   \
       40   60
    Output: 10 20 30 40 60



Constraints:
    1 ≤ Number of nodes ≤ 10^5
    1 ≤ Data of a node ≤ 10^5

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/

#include<iostream>
#include<vector>
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

vector<int> levelOrder(Node* node)
{
    queue<Node*> q;
    vector<int> arr;

    q.push(node);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        
        arr.push_back(temp->data);
    }
    return arr;
}
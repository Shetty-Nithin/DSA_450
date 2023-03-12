/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.
Link : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

Example 1:
    Input:
          3
        /   \
       2     1
    Output:
    3 1 2

Example 2:
    Input:
               7
            /     \
          9       7
        /  \     /   
       8    8   6     
     /  \
    10   9 
    Output:
    7 7 9 8 8 6 9 10

Constraints:
    1 <= N <= 104

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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

vector <int> zigZagTraversal(Node* root){
    queue<Node*> q;
    vector<int> res;
    
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        // int currLevelArr[size];
        vector<int> currLevelArr;
        
        for(int i=0; i<size; i++){
            Node* currTop = q.front();
            q.pop();
            
            int index = leftToRight ? i : size-i-1;
            currLevelArr[index] = currTop->data;
            
            if(currTop->left){
                q.push(currTop->left);
            }
            if(currTop->right){
                q.push(currTop->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto elem : currLevelArr){
            res.push_back(elem);
        }
    }
    return res;
}
/*
Given a binary tree of size N, find its reverse level order traversal.
Link : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

Example 1:
    Input :
          1
        /   \
       3     2

    Output: 3 2 1

Example 2:
    Input :
           10
          /  \
         20   30
        / \ 
       40  60
    Output: 40 60 20 30 10



Constraints:
    1 ≤ N ≤ 10^4
    
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
    Node* left;
    Node* right;
}; 

vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    vector<int> arr;

    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        
        arr.push_back(temp->data);
    }
    
    int i=0;
    int j=arr.size()-1;
    while(i<j){
       swap(arr[i], arr[j]);
       i++;
       j--;
    }
    return arr;
}
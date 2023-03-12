/*
Construct BST from given preorder traversal.
Link : https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1

Example 1:
    Input :      
    N = 5
    pre[] = {10, 30, 20, 5, 15}
    preLN[] = {N, N, L, L, L}

    Output:
              10
            /    \
          30      15
         /  \     
       20    5 

Constraints:
  1 ≤ N ≤ 10^4
  1 ≤ pre[i] ≤ 10^7
  preLN[i]: {'N', 'L'}

  Expected Time Complexity: O(N)
  Expected Auxiliary Space: O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

struct Node* solve(int size, int pre[], char preLN[], int &index){
    if(index >= size){
        return NULL;
    }
    
    Node* newNode = new Node(pre[index]);
    if(preLN[index++] == 'L'){
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    newNode->left = solve(size, pre, preLN, index);
    newNode->right = solve(size, pre, preLN, index);
    
    return newNode;
}

struct Node *constructTree(int n, int pre[], char preLN[]){
    int index = 0;
    return solve(n, pre, preLN, index); 
}
/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.
Link : https://practice.geeksforgeeks.org/problems/construct-tree-1/1
Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/

Example 1:
    Input:
    N = 4
    inorder[] = {1 6 8 7}
    preorder[] = {1 6 7 8}
    Output: 8 7 6 1

Example 2:
    Input:
    N = 6
    inorder[] = {3 1 4 0 5 2}
    preorder[] = {0 1 3 4 2 5}
    Output: 3 4 1 5 2 0
    Explanation: The tree will look like
          0
        /   \
       1     2
     /  \   /
    3   4  5


Constraints:
    1<=Number of Nodes<=1000

    Expected Time Complexity: O(N*N).
    Expected Auxiliary Space: O(N).
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val){
      data = val;
      left = NULL;
      right = NULL;
  }
};

//approach 1
int findPosition(int in[], int element, int size){
    for(int i=0; i<size; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}
    
Node* solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size){
    if(preOrderIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    int element = pre[preOrderIndex++];
    Node* root = new Node(element);
    
    int position = findPosition(in, element, size);
    
    root->left = solve(in, pre, preOrderIndex, inOrderStart, position-1, size);
    root->right = solve(in, pre, preOrderIndex, position+1, inOrderEnd, size);
    
    return root;    
}    
    
Node* buildTree(int in[],int pre[], int n){
    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
    
    return ans;
}





//approach 2 - using map for finding the position.
void createMapping(int in[], map<int, int> &m, int size){
    for(int i=0; i<size; i++){
        m[in[i]] = i; 
    }
}
    
Node* solve(int in[], int pre[], int &preOrderIndex, 
                        int inOrderStart, int inOrderEnd, int size, map<int, int> m){
    if(preOrderIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    int element = pre[preOrderIndex++];
    Node* root = new Node(element);
    
    int position = m[element];
    
    root->left = solve(in, pre, preOrderIndex, inOrderStart, position-1, size, m);
    root->right = solve(in, pre, preOrderIndex, position+1, inOrderEnd, size, m);
    
    return root;
    
}
    
Node* buildTree(int in[], int pre[], int n){
    int preOrderIndex = 0;
    map<int, int> m;// node to index mapping
    createMapping(in, m, n);
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, m);
    
    return ans;
}



//--------------------Using preOrder and postOrder-------------
// void createMapping(int in[], map<int, int> &m, int size){
//     for(int i=0; i<size; i++){
//         m[in[i]] = i; 
//     }
// }
    
// Node* solve(int in[], int post[], int &postOrderIndex, 
//                         int inOrderStart, int inOrderEnd, int size){
//     if(preOrderIndex < 0 || inOrderStart > inOrderEnd){
//         return NULL;
//     }
    
//     int element = post[postOrderIndex--];
//     Node* root = new Node(element);
    
//     int position = m[element];
    

    // we need to build the right tree first in this example.
//     root->right = solve(in, post, postOrderIndex, position+1, inOrderEnd, size);
//     root->left = solve(in, post, postOrderIndex, inOrderStart, position-1, size);
    
//     return root;
    
// }
    
// Node* buildTree(int in[],int post[], int n)
// {
//     int postOrderIndex = n-1;
//     map<int, int> m;// node to index mapping
//     createMapping(in, m, n);
//     Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, m);
    
//     return ans;
// }
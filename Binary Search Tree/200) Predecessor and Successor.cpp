/*
There is BST given with root node with key part as integer only.
You need to find the inorder successor and predecessor of a given key.
In case, if the either of predecessor or successor is not found print -1.
Link : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

Input:
    Then T test cases follow. Each test case contains n denoting the number
    of edges of the BST. The next line contains the edges of the BST.
    The last line contains the key.
Output:
    Print the predecessor followed by successor for the given key.
    If the predecessor or successor is not found print -1.

Example 1:
    Input:
    6
    50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
    65
    
    Output:
    60 70

Example 2:  
    6
    50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
    100

    Output:
    80 -1

Constraints:
    1<=T<=100
    1<=n<=100
    1<=data of node<=100
    1<=key<=100
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	struct Node *left, *right;
};


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){  
    if (root == NULL){
      return;   
    }
 
    if (root->key == key){
        if (root->left != NULL){
            Node* tmp = root->left;
            while (tmp->right){
                tmp = tmp->right;
            }
            pre = tmp;
        }
        if (root->right != NULL){
            Node* tmp = root->right;
            while (tmp->left){
                tmp = tmp->left;
            }
            suc = tmp;
        }
        return ;
    }
    else if (root->key > key){
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else{
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}

// void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
//     Node* temp = root;
//     while(temp->key != key){
//         if(temp->key > key){
//             suc = temp;
//             temp = temp->left;
//         }else{
//             pre = temp;
//             temp = temp->right;
//         }
//     }
    

//     //predecessor
//     Node* tempLeft = temp->left;
//     while(tempLeft->right){
//         tempLeft = tempLeft->right;
//     }
//     pre = tempLeft;
    
//     //successor
//     Node* tempRight = temp->right;
//     while(tempRight->left){
//         tempRight = tempRight->left;
//     }
//     suc = tempRight;
// }
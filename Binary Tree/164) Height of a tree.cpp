/* 
Given a binary tree, find its height.
Link : https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

Example 1:
    Input:
        1
      /  \
     2    3
    Output: 2

Example 2:
    Input:
     2
      \
        1
      /
     3
    Output: 3   



Constraints:
    1 <= Number of nodes <= 10^5
    1 <= Data of a node <= 10^5

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)

*/

#include<iostream>
#include<vector>
#include<stack>
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
//-----------------recursive way----------------------------------
int height(struct Node* node){
    if(node == NULL){
        return 0;
    }
    
    int left = height(node->left);
    int right = height(node->right);
    
    int res = max(left, right)+1;
    return res;
}

//--------------------Iterative way----------------------------------
int height(struct Node* node){
    queue<Node*> q;
    int count = 0;
    
    q.push(node);
    q.push(NULL);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            count++;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return count;
}
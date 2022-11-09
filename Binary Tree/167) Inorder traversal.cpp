/*
Given a binary tree, write an iterative and recursive solution to traverse the tree using inorder traversal.
Link : https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
*/

#include <iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

//----------------------------Recursive way--------------------------------
void inorder(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


//-------------------------------Iterative way---------------------------
void inorderIterative(Node* root)
{
    stack<Node*> stack;
 
    Node* curr = root;
    while (!stack.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}
/*
Given a binary tree, write an iterative and recursive solution to traverse the tree using preorder traversal.
Link : https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
 
    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

//----------------------------Recursive way--------------------------------
void preorder(Node* root){
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//-------------------------Iterative way--------------------------------------
//approach 1
void preorderIterative(Node* root){
    if (root == nullptr)
    return;
 
    stack<Node*> stack;
    stack.push(root);
 
    while (!stack.empty()){
        Node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // first right goes to the stack and then left, 
        // so while poping left will come first and then right
        if (curr->right) {
            stack.push(curr->right);
        }
        if (curr->left) {
            stack.push(curr->left);
        }
    }
}

//approach 2
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
vector<int> preorderTraversal(TreeNode* root) { 
    stack<TreeNode*> st;
    vector<int> res;
    TreeNode* current = root;
    
    while(!st.empty() || current != NULL){
        if(current != NULL){
            res.push_back(current->val);
            st.push(current);
            current = current->left;
        }else{
            TreeNode* temp = st.top();
            st.pop();
            
            current = temp->right;
        }
    }
    return res;
}
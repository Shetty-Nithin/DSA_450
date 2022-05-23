/*
Given a binary tree, write an iterative and recursive solution to traverse the tree using postorder traversal.
Link : https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
*/

#include<iostream>
#include<vector>
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
void postorder(Node* root)
{
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//--------------------------IteratiVE way---------------------------------------
//approach 1 : Using 2 stacks.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode* current = NULL;
    
    if(root == NULL){
        return res;
    }
    
    st1.push(root);
    while(!st1.empty()){
        current = st1.top();
        st1.pop();
        st2.push(current);
        
        if(current->left){
            st1.push(current->left);
        }
        if(current->right){
            st1.push(current->right);
        }
    }
    while(!st2.empty()){
        current = st2.top();
        res.push_back(current->val);
        st2.pop();
    }
    return res;
}

//approach 2 : Using 1 stack.
vector<int> postorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> res;
    TreeNode* current = root;
    
    while(!st.empty() || current != NULL){
        if(current != NULL){
            st.push(current); 
            current = current->left;
        }else{
            TreeNode* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                res.push_back(temp->val);
                st.pop();

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                }
            }
            else current = temp;
        }
    }
    return res;    
}

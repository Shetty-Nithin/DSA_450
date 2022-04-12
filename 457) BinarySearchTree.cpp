// Binary Search Tree.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinarySearchTree{
    public:
    Node* root;

    BinarySearchTree(int d){
        this->root = NULL;
    }

    Node* insert(int d){
        Node* newNode = new Node(d);

        if(this->root == NULL){
            this->root = newNode;
            return root;
        }else{
            Node* curr = this->root;
            while(true){
                if(d == curr->data){
                    // return root;
                }
                if(d < curr->data){
                    if(curr->left == NULL){
                        curr->left = newNode;
                        // return root;
                    }else{
                        curr = curr->left;
                    }
                }else if(d > curr->data){
                    if(curr->right == NULL){
                        curr->right = newNode;
                        // return root;
                    }else{
                        curr = curr->right;
                    }
                }
            }
        }
    }

    bool find(int d){
        Node* curr = this->root;
        if(this->root == NULL){
            return false;
        }
        while(curr){
            if(d == curr->data){
                return true;
            }else if(d < curr->data){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        return false;
    }

    void BSF(){   //level order traversal
        Node* node = this->root;
        queue<Node*> q;
        vector<int> res;

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
            
            res.push_back(temp->data);
        }
        print(res);
    }

    void DFS_preOrder(){
        Node* curr = this->root;
        stack<Node*> st;
        vector<int> res;
        
        while(!st.empty() || curr != NULL){
            if(curr != NULL){
                res.push_back(curr->data);
                st.push(curr);
                curr = curr->left;
            }else{
                Node* temp = st.top();
                st.pop();
                
                curr = temp->right;
            }
        }
        print(res);
    }

    void DFS_inOrder(){
        Node* curr = this->root;
        stack<Node*> stack;
        vector<int> res;

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
                res.push_back(curr->data);
    
                curr = curr->right;
            }
        }
        print(res);
    }

    void DFS_postOrder(){
        Node* curr = this->root;
        stack<Node*> st;
        vector<int> res;
        
        while(!st.empty() || curr != NULL){
            if(curr != NULL){
                st.push(curr); 
                curr = curr->left;
            }else{
                Node* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    res.push_back(temp->data);
                    st.pop();

                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        res.push_back(temp->data);
                    }
                }
                else curr = temp;
            }
        }
        print(res); 
    }

    int minimum(Node* d){
        Node* curr = d;
        while(curr->left){
            curr = curr->left;
        }
        return curr->data;
    }

    int maximum(Node* d){
        Node* curr = d;
        while(curr->right){
            curr = curr->right;
        }
        return curr->data;
    }

    Node* deleteNode(int d){
        Node* curr = this->root;
        while(curr->data != NULL){
            if(root->data == NULL){
                return this->root;
            }
            if(this->root->data == d){
                if(this->root->left == NULL && this->root->right == NULL){
                    delete this->root;
                    return NULL;
                }
                if(this->root->left != NULL && this->root->right == NULL){
                    Node* temp = root->left;
                    delete this->root;
                    return temp;
                }
                if(this->root->left == NULL && this->root->right != NULL){
                    Node* temp = root->right;
                    delete this->root;
                    return temp;
                }
                if(this->root->left != NULL && this->root->right != NULL){
                    int mini = minimum(root->right);
                    this->root->data = mini;

                    this->root->right = deleteNode(mini);
                }
            }else if(this->root->data > d){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }

    void print(vector<int> v){
        for(int i : v){
            cout << i << ", ";
        }
    }
};


int main(){

}
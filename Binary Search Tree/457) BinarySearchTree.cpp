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

    BinarySearchTree(){
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
                if(d == curr->data){ // if the data already exists, do nothing and return the root
                    return root;
                }
                if(d < curr->data){
                    if(curr->left == NULL){
                        curr->left = newNode;
                        return root;
                    }else{
                        curr = curr->left;
                    }
                }else if(d > curr->data){
                    if(curr->right == NULL){
                        curr->right = newNode;
                        return root;
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

    void BFS(){   //level order traversal
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

                    //OR
                    // int maxi = maximum(root->left);
                    // this->root->data = maxi;

                    // this->root->left = deleteNode(maxi);
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
        cout << endl;
    }
};


int main(){
   BinarySearchTree* tree = new BinarySearchTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(2);
    tree->insert(1);
    tree->insert(4);
    tree->insert(8); 
    tree->insert(7);
    tree->insert(6);
    tree->insert(9);
    tree->insert(10);

    /*
             5
          /    \
         3      8
        / \    /  \
      2    4  7    9
     /       /      \
    1       6       10

    */
    tree->BFS();
    // 5 3 8 2 4 7 9 1 6 10
    tree->DFS_postOrder();
    // 1 2 4 3 6 7 10 9 8 5
    tree->DFS_preOrder();
    // 5 3 2 1 4 8 7 6 9 10
    tree->DFS_inOrder();
    // 1 2 3 4 5 6 7 8 9 10

    cout<< tree->find(11) << endl;
    cout<< tree->find(2) << endl;
  
    cout<< tree->minimum(tree->root) << endl;
    cout<< tree->maximum(tree->root) << endl;
  
    // tree->deleteNode(1);
}
// Construction of a Binary Tree

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    void deleteTree(Node* node){
        if(node == nullptr){
            return;
        }
        
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    Node* root;

    // Constructor
    BinaryTree(){
        root = nullptr;
    }

    // Function to insert the node to the BT
    void insert(int value){
        Node* newNode = new Node(value);

        if(root == nullptr){
            root = newNode;
            return;
        }

        Node* currentNode = root;
        while(true){
            if(value < currentNode->data){
                if(currentNode->left == nullptr){
                    currentNode->left = newNode;
                    break;
                }
                currentNode = currentNode->left;
            }else{
                if(currentNode->right == nullptr){
                    currentNode->right = newNode;
                    break;
                }
                currentNode = currentNode->right;
            }
        }
    }

    // Function to traverse the BT in Pre-Order (root, left, right);
    void preOrderTraversal(Node* node){
        if (node == nullptr) {
            return;
        }

        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }


    // Function to traverse the BT in In-Order (root, left, right);
    void inOrderTraversal(Node* node){
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    // Function to traverse the BT in Post-Order (root, left, right);
    void postOrderTraversal(Node* node){
        if (node == nullptr) {
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    ~BinaryTree(){
        deleteTree(root);
    }
};

int main(){
    // Static Memory Allocation
    BinaryTree tree;

    // Insert nodes into the binary tree
    tree.insert(4);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);

    cout << "Pre-Order Traversal : " << endl;
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "In-Order Traversal : " << endl;
    tree.inOrderTraversal(tree.root);
    cout << endl;

    cout << "Post-Order Traversal: " << endl;
    tree.postOrderTraversal(tree.root);
    cout << endl;


    // Dynamic Memory Allocation
    BinaryTree* dynamicTree = new BinaryTree();

    // Insert nodes into the binary tree
    dynamicTree->insert(4);
    dynamicTree->insert(2);
    dynamicTree->insert(7);
    dynamicTree->insert(1);
    dynamicTree->insert(3);
    dynamicTree->insert(6);
    dynamicTree->insert(9);

    cout << "Pre-Order Traversal : " << endl;
    dynamicTree->preOrderTraversal(dynamicTree->root);
    cout << endl;

    cout << "In-Order Traversal : " << endl;
    dynamicTree->inOrderTraversal(dynamicTree->root);
    cout << endl;

    cout << "Post-Order Traversal: " << endl;
    dynamicTree->postOrderTraversal(dynamicTree->root);
    cout << endl;

    delete dynamicTree;

    return 0;
}
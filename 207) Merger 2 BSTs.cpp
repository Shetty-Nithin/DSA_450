/*
Given two BSTs, return elements of both BSTs in sorted form.
Link : https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

Example 1:
    Input:
    BST1:
         5
       /   \
      3     6
     / \
    2   4  
    BST2:
          2
        /   \
       1     3
              \
               7
              /
             6
    Output: 1 2 2 3 3 4 5 6 6 7
    Explanation: 
    After merging and sorting the
    two BST we get 1 2 2 3 3 4 5 6 6 7.

Example 2:
    Input:
    BST1:
         12
       /   
      9
     / \    
    6   11
      BST2:
        8
      /  \
     5    10
    /
   2
    Output: 2 5 6 8 9 10 11 12
    Explanation: 
    After merging and sorting the
    two BST we get 2 5 6 8 9 10 11 12.


Constraints:
    1 ≤ Number of Nodes ≤ 10^5

    Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
    Expected Auxiliary Space: O(Height of BST1 + Height of BST2).
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


//approach 1

class Solution
{
    public:
    void inOrder(Node* rootNode, vector<int> &output){
        if(rootNode == NULL){
            return;
        }
        
        inOrder(rootNode->left, output);
        output.push_back(rootNode->data);
        inOrder(rootNode->right, output);
    }
    
    void mergedArrays(vector<int> &a, vector<int> &b, vector<int> &mergeArray){
        int i=0;
        int j=0;
        int k=0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                mergeArray[k++] = a[i];
                i++;
            }else{
                mergeArray[k++] = b[j];
                j++;
            }
        }
        while(i < a.size()){
            mergeArray[k++] = a[i];
            i++;
        }
        while(j < b.size()){
            mergeArray[k++] = b[j];
            j++;
        }
    }
    
    Node* inOrderToBST(vector<int> &mergeArray, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = (start + end)/2;
        Node* root = new Node(mergeArray[mid]);
        root->left = inOrderToBST(mergeArray, start, mid-1);
        root->right = inOrderToBST(mergeArray, mid+1, end);
        
        return root;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> inOrder1;
        vector<int> inOrder2;
        
        inOrder(root1, inOrder1);
        inOrder(root2, inOrder2);
        
        vector<int> mergeArray(inOrder1.size() + inOrder2.size());
        mergedArrays(inOrder1, inOrder2, mergeArray);
        
        Node* root = inOrderToBST(mergeArray, 0, mergeArray.size()-1);
        
        vector<int> ans;
        inOrder(root, ans);
        
        return ans;
    }
};

//approach 2:
/*
class Solution {
    public:

    void convertInto_DLL(Node* root, Node* &head){
        if(root == NULL){
            return;
        }
        
        convertInto_DLL(root->right, head);
        root->right = head;
        if(head != NULL){
            head->left = root;
        }
        
        head = root; //now the head will be current root node
        convertInto_DLL(root->left, head);
    }
    
    Node* merge_DLL(Node* head1, Node* head2){
        Node* head = NULL;
        Node* tail = NULL;
        
        while(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                if(head == NULL){
                   head = head1;
                   tail = head1;
                   head1 = head1->right;
                }else{
                   tail->right = head1;
                   head1->left = tail;
                   tail = head1;
                   head1 = head1->right;
                }
            }else{
                if(head == NULL){
                   head = head2;
                   tail = head2;
                   head1 = head2->right;
                }else{
                   tail->right = head2;
                   head2->left = tail;
                   tail = head2;
                   head2 = head2->right;
                }
            }
        }
        while(head1 != NULL){
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right; 
        }
        while(head2 != NULL){
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
        return head;
    }

    int countNodes(Node* head){
        int cnt = 0;
        Node* temp = head;
        
        while(temp != NULL){
            cnt++;
            temp = temp->right;
        }
    }

    Node* sortedLL_to_BST(Node* &head, int n){
        if(n <= 0 || head == NULL){
            return NULL;
        }
        
        Node* left = sortedLL_to_BST(head, n/2);
        Node* root = head;
        root->left = left;
        
        head = head->right;
        
        root->right = sortedLL_to_BST(head, n-n/2-1);
        
        return root;
    }
    
    void inOrderOfMergedTree(Node* head, vector<int> &ans){
        int i=0;
        while(head){
            ans[i++] = head->data;
            head = head->right;
        }
    }
    
    vector<int> merge(Node *root1, Node *root2){
        Node* head1 = NULL;
        convertInto_DLL(root1, head1);
        head1->left = NULL;
        
        Node* head2 = NULL;
        convertInto_DLL(root2, head2);
        head2->left = NULL;
        
        Node* head = merge_DLL(head1, head2);
        
        // return sortedLL_to_BST(head, countNodes(head));
        vector<int> ans;
        inOrderOfMergedTree(head, ans);
        
        return ans;
    }
};

*/
/*
Given a Binary Search Tree and a target sum. Check whether there's a 
pair of Nodes in the BST with value summing up to the target sum. 
Link : https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

Example 1:
    Input:
          2
        /   \
       1     3
    sum = 5
    Output: 1 
    Explanation: 
    Nodes with value 2 and 3 sum up to 5.

Example 2:
    Input:
              6
             /    
            5     
           /
          3 
        /  \
       1    4
    sum = 2
    Output: 0 
    Explanation: 
    There's no pair that sums up to 2.


Constraints:
    1 ≤ Number of Nodes ≤ 10^5
    1 ≤ Sum ≤ 10^6

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the BST).
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

class Solution{
  public:
    void inOrder(struct Node* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
    int isPairPresent(struct Node *root, int target){
        vector<int> v;
        inOrder(root, v);
        
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]+v[j] == target){
                return 1; // TRUE or FALSE
            }
            else if(v[i]+v[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return 0;
        
    }
};
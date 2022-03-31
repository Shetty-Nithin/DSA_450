/*
Given two binary trees, the task is to find if both of them are identical or not.
Link : https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

Example 1:
    Input:
     1          1
   /   \      /   \
  2     3    2     3
    Output: Yes
    Explanation: There are two trees both
    having 3 nodes and 2 edges, both trees
    are identical having the root as 1,
    left child of 1 is 2 and right child
    of 1 is 3.

Example 2:
    Input:
    1       1
  /  \     /  \
 2    3   3    2
    Output: No
    Explanation: There are two trees both
    having 3 nodes and 2 edges, but both
    trees are not identical.

Constraints:
    1 <= Number of nodes <= 105
    1 <=Data of a node <= 105

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the Tree).
*/

#include <bits/stdc++.h>
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

bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if((r1 == NULL && r2 != NULL) || (r2 == NULL && r1 != NULL)){
        return false;
    }
    
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    
    bool val = r1->data == r2->data;
    
    if(left && right && val){
        return true;
    }
    else return false;
}
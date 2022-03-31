/*
The diameter of a tree (sometimes called the width) is the number of nodes on
the longest path between two end nodes. The diagram below shows two trees 
each with diameter nine, the leaves that form the ends of the longest path 
are shaded (note that there is more than one path in each tree of length nine,
but no path longer than nine nodes).
Link : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

Example 1:
    Input:
         1
        /  \
       2    3
    Output: 3

Example 2:
    Input:
              10
            /   \
          20    30
        /   \ 
       40   60
    Output: 4


Constraints:
    1 <= Number of nodes <= 10000
    1 <= Data of a node <= 1000

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the Tree).

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


pair<int, int> diameterFun(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        //first value of the pair is the diameter and 
        //second value is height.
        return p;
    }
    
    pair<int, int> left = diameterFun(root->left);
    pair<int, int> right = diameterFun(root->right);
    
    //the longest diameter could be present in the left side or right side
    // or right+node+left.
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;//height of left + height of right + parent node
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second)+1;
    
    return ans;
}
int diameter(Node* root) {
    return diameterFun(root).first;
}
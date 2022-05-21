/*
Given a binary search tree which is also a complete binary tree. The 
problem is to convert the given BST into a Min Heap with the condition 
that all the values in the left subtree of a node should be less than 
all the values in the right subtree of the node. This condition is 
applied on all the nodes in the so converted Min Heap.

Link :  https://www.geeksforgeeks.org/convert-bst-min-heap/

Examples 1:
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

The given BST has been transformed into a Min Heap.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // save in inorder in array.
    // fill the BT in preOrder using inorder array
};

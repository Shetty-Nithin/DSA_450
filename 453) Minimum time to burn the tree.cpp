/*
Given a binary tree and a node called target. Find the minimum time required to burn
the complete binary tree if the target is set on fire. It is known that in 1 second 
all nodes connected to a given node get burned. That is its left child, right child,
and parent.
Link : https://practice.geeksforgeeks.org/problems/burning-tree/1#

Example 1:
    Input:      
               1
             /   \
            2      3
          /  \      \
         4    5      6
        / \     \
       7   8      9
                    \
                    10
    Target Node = 8
    Output: 7
    Explanation: If leaf with the value 
    8 is set on fire. 
    After 1 sec: 5 is set on fire.
    After 2 sec: 2, 7 are set to fire.
    After 3 sec: 4, 1 are set to fire.
    After 4 sec: 3 is set to fire.
    After 5 sec: 6 is set to fire.
    After 6 sec: 9 is set to fire.
    After 7 sec: 10 is set to fire.
    It takes 7s to burn the complete tree.

Example 2:
    Input:      
            1
          /   \
        2      3
      /  \      \
     4    5      7
    /    / 
   8    10
    Target Node = 10
    Output: 5


Constraints:
    1 ≤ N ≤ 10^4

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(height of tree)
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


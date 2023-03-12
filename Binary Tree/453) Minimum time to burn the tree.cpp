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

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
    Node* res = NULL;
    queue<Node*> q;
    // creating the parent map and finding the targetNode.
    q.push(root);
    nodeToParent[root] = NULL;
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp->data == target){
            res = temp;
        }
        if(temp->left){
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}

int min_time(Node* targetNode, map<Node*, Node*> nodeToParent){
    map<Node*, bool> visited;
    queue<Node*> q;
    int ans = 0;
    
    q.push(targetNode);
    visited[targetNode] = true;
    
    while(!q.empty()){
        bool flag = false;
        int size = q.size();

        // for loop => burning all the node present in the queue are burning and spreading the fre to 
        // the adjacent nodes at a signle time
        for(int i=0; i<size; i++){ 
            Node* temp = q.front();
            q.pop();
            
            if(temp->left && !visited[temp->left]){
                flag = true;
                visited[temp->left] = true;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                flag = true;
                visited[temp->right] = true;
                q.push(temp->right);
            }
            if(nodeToParent[temp] && !visited[nodeToParent[temp]]){
                flag = true;
                visited[nodeToParent[temp]] = true;
                q.push(nodeToParent[temp]);
            }
        }
        if(flag){
            ans++;
        }
    }
    return ans;
}
    
int minTime(Node* root, int target) {
    map<Node*, Node*> nodeToParent;
    // this function creates the parent children mapping as well as locate the target node
    // thats why assigning the returned value to the targetNode variable.
    Node* targetNode = createParentMapping(root, target, nodeToParent); 
    int ans = min_time(targetNode, nodeToParent);
    return ans;
}
/*
Construct BST from given preorder traversal.
Link : https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1

Example 1:
    Input :      
    N = 5
    pre[] = {10, 30, 20, 5, 15}
    preLN[] = {N, N, L, L, L}

    Output:
              10
            /    \
          30      15
         /  \     
       20    5 



Constraints:
  1 ≤ N ≤ 104
  1 ≤ pre[i] ≤ 107
  preLN[i]: {'N', 'L'}

  Expected Time Complexity: O(N)
  Expected Auxiliary Space: O(N)
*/


// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
// 	int data;
// 	Node* left, *right;

//   Node(int val){
//     this->data = val;
//     this->left = NULL;
//     this->right = NULL;
//   }
// }; 


// Node* solve(vector<int> &v, int mini, int maxi, int index){
//   if(index >= v.size()){
//     return NULL;
//   }

//   if(v[index] < mini || v[index] > maxi){
//     return NULL;
//   }

//   Node* root = new Node(v[index]);
//   index++;
//   root->left = solve(v, mini, root->data, index);
//   root->right = solve(v, root->data, maxi, index);

//   return root;
// }
// int main(){
//   int mini = INT_MIN;
//   int maxi = INT_MAX;
//   int index = 0;
//   vector<int> v = {10, 5, 1, 7, 40, 50};

//   Node* root = solve(v, mini, maxi, index); 
// }
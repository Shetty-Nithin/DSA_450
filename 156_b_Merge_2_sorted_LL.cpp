/*
Given two sorted linked lists consisting of N and M nodes respectively.
The task is to merge both of the list (in-place) and return head of the
merged list.

Link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

Example 1:
    Input:
    N = 4, M = 3 
    valueN[] = {5,10,15,40}
    valueM[] = {2,3,20}
    Output: 2 3 5 10 15 20 40
    Explanation: After merging the two linked
    lists, we have merged list as 2, 3, 5,
    10, 15, 20, 40.

Example 2:
    Input:
    N = 2, M = 2
    valueN[] = {1,1}
    valueM[] = {2,4}
    Output:1 1 2 4
    Explanation: After merging the given two
    linked list , we have 1, 1, 2, 4 as
    output.

Constraints:
    1 <= N, M <= 10^4
    1 <= Node's data <= 10^5

    Expected Time Complexity : O(n+m)
    Expected Auxilliary Space : O(1)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void solve(struct Node* a, struct Node* b){
    struct Node* curr_1 = a;
    struct Node* next_1 = curr_1->next;
    
    struct Node* curr_2 = b;
    struct Node* next_2 = curr_2->next;
    
    while(next_1 != NULL && curr_2 != NULL){
        if(curr_1->data <= curr_2->data && next_1->data >= curr_2->data){
            curr_1->next = curr_2;
            next_2 = curr_2->next;
            curr_2->next = next_1;
            
            curr_1 = curr_2;
            curr_2 = next_2;
        }else{
            curr_1 = next_1;
            next_1 = next_1->next;
        }
    }
    
    if(next_1 == NULL){
        curr_1->next = curr_2;
        return;
    }
}
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
   if(a == NULL){
       return b;
   } 
   if(b == NULL){
       return a;
   }
   
   
   if(a->data < b->data){
       solve(a, b);
       return a;
   }else{
       solve(b, a);
       return b;
   }
}
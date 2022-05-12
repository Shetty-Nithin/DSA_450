/*
Given Pointer/Reference to the head of the linked list, the task is to 
Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should 
go in the first list while splitting.

Link : https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

Example 1:
    Input:
    N = 5
    value[]  = {3,5,2,4,1}

    Output: 1 2 3 4 5

    Explanation: After sorting the given
    linked list, the resultant matrix
    will be 1->2->3->4->5.

Example 2:
    Input:
    N = 3
    value[]  = {9,15,0}

    Output: 0 9 15

    Explanation: After sorting the given
    linked list , resultant will be
    0->9->15.

Constraints:
    1 <= T <= 100
    1 <= N <= 10^5

    Expected Time Complexity: O(N*Log(N))
    Expected Auxiliary Space: O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* arb;

    Node(int val){
        data = val;
        next = NULL;
        arb = NULL;
    }
};

class Solution{
  private:
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left->data < right->data){
                temp->next = left;
                temp = left;
                left = left->next;
            }else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next; 
        }
        while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        return ans->next;
    } 
    
  public:
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left, right);
    }
};
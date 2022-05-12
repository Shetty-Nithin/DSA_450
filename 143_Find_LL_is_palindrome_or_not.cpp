/*
Given a singly linked list of size N of integers. The task is to check
if the given linked list is palindrome or not.

Link : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Example 1:
    Input:
    N = 3
    value[] = {1,2,1}
    Output: 1
    Explanation: The given linked list is
    1 2 1 , which is a palindrome and
    Hence, the output is 1.

Example 2:
    Input:
    N = 4
    value[] = {1,2,3,4}
    Output: 0
    Explanation: The given linked list
    is 1 2 3 4 , which is not a palindrome
    and Hence, the output is 0.


Constraints:
    1 <= N <= 10^5

    Expected Time Complexity: O(N)
    Expected Auxialliary Space Usage: O(1)  
    (ie, you should not use the recursive stack space as well)
    
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

class Solution{
  public:
    Node* middleNode(Node* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* tortoise = head;
        Node* hare = head->next;  
        
        while(hare != NULL && hare->next != NULL){
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        
        return tortoise;
    }
    

    Node* reverse_LL(Node *head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;
        
        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL){
            return true;
        }
        
        Node* mid = middleNode(head);
        mid->next = reverse_LL(mid->next);
        
        Node* head1 = head;
        Node* head2 = mid->next;
        
        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return true;
    }
};
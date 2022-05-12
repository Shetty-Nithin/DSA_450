/*
Given two numbers represented by two linked lists of size N and M.
The task is to return a sum list.

The sum list is a linked list representation of the addition of two
input numbers from the last.

Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Example 1:
    Input:
    N = 2
    valueN[] = {4,5}
    M = 3
    valueM[] = {3,4,5}
    Output: 3 9 0  
    Explanation: For the given two linked
    list (4 5) and (3 4 5), after adding
    the two linked list resultant linked
    list will be (3 9 0).

Example 2:
    Input:
    N = 2
    valueN[] = {6,3}
    M = 1
    valueM[] = {7}
    Output: 7 0
    Explanation: For the given two linked
    list (6 3) and (7), after adding the
    two linked list resultant linked list
    will be (7 0).


Constraints:
    1 <= N, M <= 5000

    Expected Time Complexity: O(N+M)
    Expected Auxiliary Space: O(Max(N,M)) for the resultant list.
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

class Solution
{
    public:
    Node* reverseList(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        Node* backup;
        
        while(curr != NULL){
            backup = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = backup;
        }
        
        return prev;
    } 
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int digit){
        struct Node* newNode = new Node(digit);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        int sum = 0;
        int digit = 0;
        
        struct Node* ansHead = NULL;
        struct Node* ansTail = NULL;
        
        while(first != NULL && second != NULL){
            sum = carry + first->data + second->data;
            digit = sum%10;
            carry = sum/10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            first = first->next;
            second = second->next;
        }
        while(first != NULL){
            sum = carry + first->data;
            digit = sum%10;
            carry = sum/10;
            
            insertAtTail(ansHead, ansTail, digit);
            first = first->next;
        }
        while(second != NULL){
            sum = carry + second->data;
            digit = sum%10;
            carry = sum/10;
            
            insertAtTail(ansHead, ansTail, digit);
            second = second->next;
        }
        if(carry != 0){
            insertAtTail(ansHead, ansTail, carry);
        }
        
        return ansHead;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        
        struct Node* ans = add(first, second);
        ans = reverseList(ans);
        
        return ans;
    }
};

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverseList(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        Node* backup;
        
        while(curr != NULL){
            backup = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = backup;
        }
        
        return prev;
    } 
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int digit){
        struct Node* newNode = new Node(digit);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        int sum = 0;
        int digit = 0;
        
        struct Node* ansHead = NULL;
        struct Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            
            int val1 = 0;
            if(first != NULL){
                val1 = first->data;
            }
            
            int val2 = 0;
            if(second != NULL){
                val2 = second->data;
            }
            
            sum = carry + val1 + val2;
            digit = sum%10;
            carry = sum/10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            if(first != NULL){
                first = first->next;
            }
            
            if(second != NULL){
                second = second->next;
            }
        }
      
        return ansHead;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        
        struct Node* ans = add(first, second);
        ans = reverseList(ans);
        
        return ans;
    }
};
/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s
only. The task is to segregate 0s, 1s, and 2s linked list such that all
zeros segregate to head side, 2s at the end of the linked list, and 1s
in the mid of 0s and 2s.

Link : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Example 1:
    Input:
    N = 8
    value[] = {1,2,2,1,2,0,2,2}
    Output: 0 1 1 2 2 2 2 2
    Explanation: All the 0s are segregated
    to the left end of the linked list,
    2s to the right end of the list, and
    1s in between.

Example 2:
    Input:
    N = 4
    value[] = {2,2,0,1}
    Output: 0 1 2 2
    Explanation: After arranging all the
    0s,1s and 2s in the given format,
    the output will be 0 1 2 2.

Constraints:
    1 <= N <= 10^3

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).

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

// approach 1
class Solution
{
    public:
    Node* segregate(Node *head) {
        
        Node* temp = head;
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        while(temp != NULL){
            if(temp->data == 0){
                zeroCount++;
            }else if(temp->data == 1){
                oneCount++;
            }else{
                twoCount++;
            }
            
            temp = temp->next;
        }
        
        temp = head;
        while(temp != NULL){
            if(zeroCount != 0){
                temp->data = 0;
                zeroCount--;
            }else if(oneCount != 0){
                temp->data = 1;
                oneCount--;
            }else{
                temp->data = 2;
                twoCount--;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};

// approach 2
class Solution
{
    public:
    Node* segregate(Node *head) {
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                zeroTail->next = temp;
                zeroTail = temp;
            }else if(temp->data == 1){
                oneTail->next = temp;
                oneTail = temp;
            }else{
                twoTail->next = temp;
                twoTail = temp;
            }
            
            temp = temp->next;
        }
        
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
            oneTail->next = twoHead->next;
        }else{
            zeroTail->next = twoHead->next;
        }
        twoTail->next = NULL;
        
        return zeroHead->next;
    }
};
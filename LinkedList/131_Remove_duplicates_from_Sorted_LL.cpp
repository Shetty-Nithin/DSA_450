/*
Given a singly linked list consisting of N nodes. The task is to remove
duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). 
      The nodes are arranged in a sorted way.

Link : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

Example 1:
    Input:
    LinkedList: 2->2->4->5
    Output: 2 4 5
    Explanation: In the given linked list 
    2 ->2 -> 4-> 5, only 2 occurs more 
    than 1 time.

Example 2:
    Input:
    LinkedList: 2->2->2->2->2
    Output: 2
    Explanation: In the given linked list 
    2 ->2 ->2 ->2 ->2, 2 is the only element
    and is repeated 5 times.


Constraints:
    1 <= Number of nodes <= 10^4

    Expected Time Complexity : O(N)
    Expected Auxilliary Space : O(1)
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

};

Node *removeDuplicates(Node *head)
{
    if(head == NULL){
        return NULL;
    }
    
    Node* curr = head;
    Node* temp;
    while(curr != NULL){
        temp = curr->next;
        while(temp != NULL && temp->data == curr->data){
            temp = temp->next;
        }
        curr->next = temp;
        curr = temp;
    }
    
    return head;
}

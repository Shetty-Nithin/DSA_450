/*
Given an unsorted linked list of N nodes. The task is to remove duplicate
elements from this unsorted Linked List. When a value appears in multiple
nodes, the node which appeared first should be kept, all others duplicates
are to be removed.

Link : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

Example 1:
    Input:
    N = 4
    value[] = {5,2,2,4}
    Output: 5 2 4
    Explanation:Given linked list elements are
    5->2->2->4, in which 2 is repeated only.
    So, we will delete the extra repeated
    elements 2 from the linked list and the
    resultant linked list will contain 5->2->4

Example 2:
    Input:
    N = 5
    value[] = {2,2,2,2,2}
    Output: 2
    Explanation:Given linked list elements are
    2->2->2->2->2, in which 2 is repeated. So,
    we will delete the extra repeated elements
    2 from the linked list and the resultant
    linked list will contain only 2.


Constraints:
    1 <= size of linked lists <= 106
    0 <= numbers in list <= 104

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
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

class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        if(head == NULL){
            return NULL;
        }
        
        map<int, bool> visited;
        
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            if(visited[curr->data] == true){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                visited[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
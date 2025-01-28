/*
Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to
the node at position X. If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present.  

Link : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

Example 1:
    Input:
    N = 3
    value[] = {1,3,4}
    X = 2
    Output: 1
    Explanation: The link list looks like
    1 -> 3 -> 4
         ^    |
         |____|    
    A loop is present. If you remove it 
    successfully, the answer will be 1. 

Example 2:
    Input:
    N = 4
    value[] = {1,8,3,4}
    X = 0
    Output: 1
    Explanation: The Linked list does not 
    contains any loop. 

Example 3:
    Input:
    N = 4
    value[] = {1,2,3,4}
    X = 1
    Output: 1
    Explanation: The link list looks like 
    1 -> 2 -> 3 -> 4
    ^              |
    |______________|
    A loop is present. 
    If you remove it successfully, 
    the answer will be 1.

Constraints:
    1 ≤ N ≤ 10^4

    Expected time complexity: O(N)
    Expected auxiliary space: O(1)
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

// class Solution
// {
//     public:
//     Node* detectLoop(Node* head)
//     {
//         if(head == NULL){
//             return NULL;
//         }
        
//         Node* slow = head;
//         Node* fast = head;
        
//         while(fast != NULL && fast->next != NULL){
//             fast = fast->next->next;
//             slow = slow->next;
            
//             if(slow == fast){
//                 return slow;
//             }
//         }
//         return NULL;
//     }

//     void removeLoop(Node* head){
//        if(head == NULL){
//            return;
//        } 

//        Node* slowMeetsFastAt = detectLoop(head);
//        Node* slow = head;

//        while(slowMeetsFastAt->next != slow){
//            slow = slow->next;
//            slowMeetsFastAt = slowMeetsFastAt->next;
//        }

//        slowMeetsFastAt->next = NULL;
//     }
// };


//Solution:
class Solution
{
    public:
    Node* detectLoop(Node* head)
    {
        if(head == NULL){
            return NULL;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }

    Node* getStaringNodeOfLoop(Node* head){
        
       if(head == NULL){
           return NULL;
       } 

       Node* slowMeetsFastAt = detectLoop(head);
       Node* slow = head;

       while(slow != slowMeetsFastAt){
           slow = slow->next;
           slowMeetsFastAt = slowMeetsFastAt->next;
       }

       return slow;
    }

    void removeLoop(Node* head){
        
        if(head == NULL){
           return;
        } 
        
        if(detectLoop(head)){
            Node* FristNodeOfLoop = getStaringNodeOfLoop(head);
            Node* temp = FristNodeOfLoop;
            
            while(temp->next != FristNodeOfLoop){
               temp = temp->next;
            }
            temp->next = NULL;
        }
    }
};
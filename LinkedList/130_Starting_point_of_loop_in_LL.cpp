/*
Write a function findFirstLoopNode() that checks whether a given Linked
List contains a loop. If the loop is present then it returns point to
the first node of the loop. Else it returns NULL.

Link : https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
Link : https://ide.geeksforgeeks.org/

Algorithm: 
 1. Detect whether the LL is looped or not using Floyd's algorithm
 2. After slow meets fast, start slow from the head again.
 3. Now jump both slow and fast by one step.
 4. Now the meeting point will be the starting node of the loop.

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

class Solution{
    public:
    Node* detectLoop(Node* head){
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
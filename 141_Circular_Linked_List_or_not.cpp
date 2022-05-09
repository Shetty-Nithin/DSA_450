/*
Given head, the head of a singly linked list, find if the linked list
is circular or not. A linked list is called circular if it not NULL
terminated and all nodes are connected in the form of a cycle.
An empty linked list is considered as circular.
Note: The linked list does not contains any inner loop.

Link : https://practice.geeksforgeeks.org/problems/circular-linked-list/1

Example 1:
    Input:
    LinkedList: 1->2->3->4->5
    (the first and last node is connected,
    i.e. 5 --> 1)
    Output: 1

Example 2:
    Input:
    LinkedList: 2->4->6->7->5->1
    Output: 0


Constraints:
    1 <=Number of nodes<= 100

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

bool isCircular(struct Node *head){
    struct Node* temp = head->next;
    
    while(temp != head && temp != NULL){
        temp = temp->next;
    }
    
    if(temp == head){
        return true;
    }else{
        return false;
    }
}

// approach 2
// bool isCircular(struct Node *head){
//     if(head == NULL){
//         return true;
//     }
    
//     map<Node*, bool> m;
//     while(){
//         if(head == NULL){
//             return false;
//         }else if(m[head] == true){
//             return true;
//         }else{
//             m.make_pair(head, true);
//             head = head->next;
//         }
//     }
// }
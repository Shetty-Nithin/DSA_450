/*
Given a linked list of N nodes. The task is to reverse this list.
Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/
Link : https://leetcode.com/problems/reverse-linked-list/description/

Example 1:
    Input:
    LinkedList: 1->2->3->4->5->6
    Output: 6 5 4 3 2 1
    Explanation: After reversing the list, 
    elements are 6->5->4->3->2->1.

Example 2:
    Input:
    LinkedList: 2->7->8->9->10
    Output: 10 9 8 7 2
    Explanation: After reversing the list,
    elements are 10->9->8->7->2.

Constraints:
    1 <= N <= 10^4  

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).
*/

#include<bits/stdc++.h>
#include "common.h"
using namespace std;

// class Node{
//     public:
//     int data;
//     Node *next;
// };

// Iterative way
class Solution_1{
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
};

// Recursive way
class Solution_2{
    public:
    void reverseLL(Node* &head, Node* prev, Node* curr){
        if(curr == NULL){
            head = prev;
            return;
        }
        
        Node* backup = curr->next;
        curr->next = prev;
        
        reverseLL(head, curr, backup);
    }
    Node* reverseList(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        reverseLL(head, prev, curr);
        
        return head;
    }
    
};

int main(){
    singly_linked_list* sll = new singly_linked_list();
    sll->insertAtHead(8);
    sll->insertAtHead(6);
    sll->insertAtHead(4);
    sll->insertAtHead(2);
    sll->insertAtHead(10);
    sll->print();
    
    // Solution_1* s1 = new Solution_1();
    // sll->head = s1->reverseList(sll->head);
    // cout << "reversed through solution_1 : ";
    // sll->print();

    Solution_2* s2 = new Solution_2();
    sll->head = s2->reverseList(sll->head);
    cout << "reversed through solution_2 : ";
    sll->print();
}

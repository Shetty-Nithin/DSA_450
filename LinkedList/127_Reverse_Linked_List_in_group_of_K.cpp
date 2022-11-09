/*
Given a linked list of size N. The task is to reverse every k nodes
(where k is an input to the function) in the linked list.
If the number of nodes is not a multiple of k then left-out nodes, 
in the end, should be considered as a group and must be reversed.

Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Example 1:
    Input:
    LinkedList: 1->2->2->4->5->6->7->8
    K = 4
    Output: 4 2 2 1 8 7 6 5 
    Explanation: 
    The first 4 elements 1,2,2,4 are reversed first 
    and then the next 4 elements 5,6,7,8. Hence, the 
    resultant linked list is 4->2->2->1->8->7->6->5.

Example 2:
    Input:
    LinkedList: 1->2->3->4->5
    K = 3
    Output: 3 2 1 5 4 
    Explanation: 
    The first 3 elements are 1,2,3 are reversed 
    first and then elements 4,5 are reversed.Hence, 
    the resultant linked list is 3->2->1->5->4.
 
Constraints:
    1 <= N <= 10^4
    1 <= k <= N

    Expected Time Complexity : O(N)
    Expected Auxilliary Space : O(1)
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL){
            return NULL;
        }

        node* prev = NULL;
        node* curr = head;
        node* backup = curr->next;
        int count = 0;
        
        while(curr != NULL && count != k){
            backup = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = backup;
            count++;
        }
        
        if(curr != NULL){
            head->next = reverse(curr, k);
        }
        
        return prev;
    }
};
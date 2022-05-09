/*
Middle of the Linked List.
Link : https://leetcode.com/problems/middle-of-the-linked-list/

Example 1:
    Input: head = [1,2,3,4,5]
    Output: [3,4,5]
    Explanation: The middle node of the list is node 3.

Example 2:
    Input: head = [1,2,3,4,5,6]
    Output: [4,5,6]
    Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
    

Constraints:
    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* tortoise = head;
        ListNode* hare = head->next;  
        
        while(hare != NULL){
            hare = hare->next;
            if(hare != NULL){
                hare = hare->next;
            }
            
            tortoise = tortoise->next;
        }
        
        return tortoise;
    }
};

// Another way is to find the mid is : 
// * Find the length of the linked list.
// * Run the while loop for length/2 times.
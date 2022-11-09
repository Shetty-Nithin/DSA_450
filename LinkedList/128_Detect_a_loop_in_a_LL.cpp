/*
Given a linked list of N nodes. The task is to check if the linked list
has a loop. Linked list can contain self loop.

Link : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
Link : https://leetcode.com/problems/linked-list-cycle-ii/description/

Example 1:
    Input:
    N = 3
    value[] = {1,3,4}
    x(position at which tail is connected) = 2
    Output: True
    Explanation: In above test case N = 3.
    The linked list with nodes N = 3 is
    given. Then value of x=2 is given which
    means last node is connected with xth
    node of linked list. Therefore, there
    exists a loop.

Example 2:
    Input:
    N = 4
    value[] = {1,8,3,4}
    x = 0
    Output: False
    Explanation: For N = 4 ,x = 0 means
    then lastNode->next = NULL, then
    the Linked list does not contains
    any loop.

Constraints:
    1 ≤ N ≤ 104
    1 ≤ Data on Node ≤ 10^3

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)

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

// approach 1 with map.
class Solution1
{
    public:
    bool detectLoop(Node* head)
    {
        if(head == NULL){
            return false;
        }
        
        map<Node*, bool> visited;
        
        while(head != NULL){ 
            if(visited[head] == true){
                return true;
            }else{
                visited[head] = true;
                head = head->next;
            }
        }
        return false;
    }
};

// appraoch 2 with Floyd's algorithm, without using extra space.
class Solution2
{
    public:
    bool detectLoop(Node* head)
    {
        if(head == NULL){
            return false;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
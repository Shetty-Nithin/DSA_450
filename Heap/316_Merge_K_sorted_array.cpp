/*
Given K sorted arrays arranged in the form of a matrix of size K*K.
The task is to merge them into one sorted array.

Link : https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
Link : https://leetcode.com/problems/merge-k-sorted-lists/description/

Example 1:
    Input:
    K = 3
    arr[][] = {{1,2,3},
               {4,5,6},
               {7,8,9}}

    Output: 1 2 3 4 5 6 7 8 9

    Explanation:Above test case has 3 sorted
    arrays of size 3, 3, 3
    arr[][] = [[1, 2, 3],
               [4, 5, 6], 
               [7, 8, 9]]
    The merged list will be 
    [1, 2, 3, 4, 5, 6, 7, 8, 9].

Example 2:
    Input:
    K = 4
    arr[][]={{1,2,3,4},
             {2,2,3,4},
             {5,5,6,6},
             {7,8,9,9}}

    Output:
    1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 

    Explanation: Above test case has 4 sorted
    arrays of size 4, 4, 4, 4
    arr[][] = [[1, 2, 2, 2],
               [3, 3, 4, 4],
               [5, 5, 6, 6],
               [7, 8, 9, 9]]
    The merged list will be 
    [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
    6, 6, 7, 8, 9, 9 ].


Constraints:
    1 <= K <= 100

    Expected Time Complexity: O(K2*Log(K))
    Expected Auxiliary Space: O(K)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    int row;
    int col;
    
    Node(int val, int row, int col){
        data = val;
        this->row = row;
        this->col = col;
    }
};  

class compare {
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*, vector<Node*>, compare> min_heap;
        
        for(int i=0; i<K; i++){
            Node* temp = new Node(arr[i][0], i, 0);
            min_heap.push(temp);
        }
        
        vector<int> ans;
        while(min_heap.size() > 0){
            Node* topVal = min_heap.top();
            ans.push_back(topVal->data);
            min_heap.pop();
            
            int i = topVal->row;
            int j = topVal->col;
            
            if(j+1 < arr[i].size()){
               Node* nextNode = new Node(arr[i][j+1], i, j+1);
               min_heap.push(nextNode);
            }
        }
        return ans;
    }
};


// leetcode problem : slight variation
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<bits/stdc++.h>

class compare {
public:
    bool operator()(ListNode* n1, ListNode* n2){
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,  compare> min_heap;

        for(ListNode* list : lists){
            if(list != nullptr){
                min_heap.push(list);
            }
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(!min_heap.empty()){
            ListNode* topNode = min_heap.top();
            min_heap.pop();

            if(head == nullptr){
                head = tail = topNode;
            }else{
                tail->next = topNode;
                tail = topNode;
            }

            if(topNode->next != nullptr){
                min_heap.push(topNode->next);
            }
        }
        
        return head;
    }
};
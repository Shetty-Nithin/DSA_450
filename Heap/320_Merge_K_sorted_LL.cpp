/*
Given K sorted linked lists of different sizes. The task is to merge 
them in such a way that after merging they will be a single sorted 
linked list.

Link : https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
Link : https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772

Example 1:
    Input:
    K = 4
    value = {{1,2,3},{4 5},{5 6},{7,8}}

    Output: 1 2 3 4 5 5 6 7 8

    Explanation:
    The test case has 4 sorted linked 
    list of size 3, 2, 2, 2
    1st    list     1 -> 2-> 3
    2nd   list      4->5
    3rd    list      5->6
    4th    list      7->8
    The merged list will be
    1->2->3->4->5->5->6->7->8.

Example 2:
    Input:
    K = 3
    value = {{1,3},{4,5,6},{8}}

    Output: 1 3 4 5 6 8

    Explanation:
    The test case has 3 sorted linked
    list of size 2, 3, 1.
    1st list 1 -> 3
    2nd list 4 -> 5 -> 6
    3rd list 8
    The merged list will be
    1->3->4->5->6->8.

Constraints
    1 <= K <= 10^3

    Expected Time Complexity: O(nk Logk)
    Expected Auxiliary Space: O(k)
    Note: n is the maximum size of all the k link list
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class compare {
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
	priority_queue<Node<int>*, vector<Node<int>*>, compare> min_heap;

	int k = listArray.size();
	if(k == 0){
		return NULL;
	}
	for(int i=0; i<k; i++){
		if(listArray[i] != NULL){
			min_heap.push(listArray[i]);
		}
	}

	Node<int>* head = NULL;
	Node<int>* tail = NULL;
	while(min_heap.size() > 0){
		Node<int>* topVal = min_heap.top();
		min_heap.pop();
		
		if(topVal->next != NULL){
			min_heap.push(topVal->next);
		}
		if(head == NULL){
			head = topVal;
			tail = topVal;
		}else{
			tail->next = topVal;
			tail = topVal;
		}
	}
	return head;
}
/*
Given a stack, the task is to sort it such that the top of the stack has 
the greatest element.

Link : https://practice.geeksforgeeks.org/problems/sort-a-stack/1

Example 1:
    Input:
    Stack: 3 2 1
    Output: 3 2 1

Example 2:
    Input:
    Stack: 11 2 32 3 41
    Output: 41 32 11 3 2

Constraints:
    1<=N<=100

    Expected Time Complexity: O(N*N)
    Expected Auxilliary Space: O(N) recursive.
*/

#include<iostream>
#include<stack>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void sortedInsert(stack<int> &s, int top_val){
    if(s.empty() || (s.top() <= top_val)){
        s.push(top_val);
        return;
    }
    
    int backup = s.top();
    s.pop();
    sortedInsert(s, top_val);
    s.push(backup);
}

void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   
   int top_val = s.top();
   s.pop();
   sort();
   sortedInsert(s, top_val);
}
/*
Reverse a given stack of integers using recursion.
Link : https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875


*/


#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }
    int num2 = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(num2);
}


void reverseStack(stack<int> &stack) {
    if(stack.empty()){
    	return;
    }
    int num = stack.top();
    stack.pop();
    
    reverseStack(stack);
    insertAtBottom(stack, num);
}
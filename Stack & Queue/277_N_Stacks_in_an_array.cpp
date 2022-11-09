/*
Design a data structure to implement ‘N’ stacks using a single array of 
size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the 
element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is 
empty, otherwise, returns the popped element.

Link : https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271

Example 1:
    input
    3 6 5
    1 10 1
    1 20 1
    1 30 2
    2 1
    2 2

    output
    True 
    True
    True
    20
    30

    explanation:
    For the given input, we have the number of stacks, N = 3, size of the array, S = 6 and number of queries, Q = 5.
    Operations performed on the stack are as follows:
    push(10, 1): Push element ‘10’ into the 1st stack. This returns true.
    push(20, 1): Push element ‘20’ into the 1st stack. This returns true.
    push(30, 2): Push element ‘30’ into the 2nd stack. This returns true.
    pop(1): Pop the top element from the 1st stack. This returns 20.
    pop(2): Pop the top element from the 2nd stack. This returns 30.

Example 2:
    input
    1 5 5
    1 15 1
    1 25 1
    2 1
    1 30 1
    2 1

    output
    True
    True
    25
    True
    30

Constraints :
    1 <= N <= S <= 1000
    1 <= Q <= 10^5 
    1 <= P <= 2
    1 <= X <= 10^5

    Time Limit: 1 sec
*/
  
#include<iostream>
#include<stack>
using namespace std;

class NStack{
    int *arr;
    int *next;
    int *top;
    
    int n, s; // number of stacks and size of the array
    int freeSpot;
public:
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int(s);
        top = new int(n);
        next = new int(s);
        
        for(int i=0; i<n; i++){
            top[i] = -1;
        }  
        
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;  

        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeSpot == -1){
            return false;
        }
        
        int index = freeSpot;
        freeSpot = next[index]; // updating the freeSpot for next push
        arr[index] = x;         // pushing the data into the array
        next[index] = top[m-1];
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1){
            return -1;
        }
        
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        
        return arr[index];
    }
};
/*
Your task is to implement  2 stacks in one array efficiently.
Link : https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

Example 1:
    Input:
    push1(2)
    push1(3)
    push2(4)
    pop1()
    pop2()
    pop2()

    Output:
    3 4 -1

    Explanation:
    push1(2) the stack1 will be {2}
    push1(3) the stack1 will be {2,3}
    push2(4) the stack2 will be {4}
    pop1()   the poped element will be 3 
    from stack1 and stack1 will be {2}
    pop2()   the poped element will be 4 
    from stack2 and now stack2 is empty
    pop2()   the stack2 is now empty hence -1.


Constraints:
    1 <= Number of queries <= 100
    1 <= value in the stack <= 100
    The sum of elements in both the stacks < size of the given array

    Expected Time Complexity: O(1) for all the four methods.
    Expected Auxiliary Space: O(1) for all the four methods.
*/


#include<iostream>
#include<stack>
using namespace std;

class twoStacks{
    int *arr;
    int size;
    int top1, top2;

    public:
    twoStacks(int s){
        size = s;
        arr = new int[s];
        top1 = -1;
        top2 = size;
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

void twoStacks :: push1(int x)
{
    if((top2 - top1) > 1){
        top1++;
        arr[top1] = x;
    }
}
   
void twoStacks ::push2(int x)
{
    if((top2 - top1) > 1){
        top2--;
        arr[top2] = x;
    }
}
   
int twoStacks ::pop1()
{
    if(top1 >= 0){
        int ans = arr[top1];
        top1--;
        return ans;
    }else{
        return -1;
    }
}

int twoStacks :: pop2()
{
    if(top2 < size){
        int ans = arr[top2];
        top2++;
        return ans;
    }else{
        return -1;
    }
}
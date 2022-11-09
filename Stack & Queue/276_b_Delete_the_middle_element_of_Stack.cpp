/*
Given a stack with push(), pop(), empty() operations, delete the middle 
of the stack without using any additional data structure.
Middle: ceil((size_of_stack+1)/2) (1-based index)

Link : https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/

Example 1:
    Input: 
    Stack = {1, 2, 3, 4, 5}

    Output:
    ModifiedStack = {1, 2, 4, 5}

    Explanation:
    As the number of elements is 5 , 
    hence the middle element will be the 3rd
    element which is deleted

Example 2:
    Input: 
    Stack = {1 2 3 4}

    Output:
    ModifiedStack = {1 3 4}

    Explanation:
    As the number of elements is 4 , 
    hence the middle element will be the 2nd
    element which is deleted

Constraints:
    2 ≤ size of stack ≤ 100

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/


#include<iostream>
#include<stack>
using namespace std;

class Solution
{
    private:
    void solve(stack<int> &s, int sizeOfStack, int count){
        if(count == sizeOfStack/2){
            s.pop();
            return;
        }
        
        int temp = s.top();
        s.pop();
        solve(s, sizeOfStack, count+1);
        s.push(temp);
    }
    public:
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        solve(s, sizeOfStack, count);
    }
};
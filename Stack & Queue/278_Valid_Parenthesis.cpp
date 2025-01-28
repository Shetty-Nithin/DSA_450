/*
Given an expression string x. Examine whether the pairs and the orders 
of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' 
for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Link : https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
Link : https://leetcode.com/problems/valid-parentheses/description/

Example 1:
    Input:
    {([])}

    Output: 
    true

    Explanation: 
    { ( [ ] ) }. Same colored brackets can form 
    balaced pairs, with 0 number of 
    unbalanced bracket.

Example 2:
    Input: 
    ()

    Output: 
    true

    Explanation: 
    (). Same bracket can form balanced pairs, 
    and here only 1 type of bracket is 
    present and in balanced way.

Example 3:
    Input: 
    ([]

    Output: 
    false

    Explanation: 
    ([]. Here square bracket is balanced but 
    the small bracket is not balanced and 
    Hence , the output will be unbalanced.

Constraints:
    1 ≤ |x| ≤ 32000

    Expected Time Complexity: O(|x|)
    Expected Auixilliary Space: O(|x|)
*/

#include<iostream>
#include<stack>
using namespace std;

class Solution
{   
    private:
    bool matches(char top_val, char ch){
        if((ch == ']' && top_val == '[') || 
           (ch == ')' && top_val == '(') ||
           (ch == '}' && top_val == '{') ){
               return true;
        }else{
            return false;
        }
    }
    public:
    bool ispar(string x){
        stack<int> stk;
        for(int i=0; i<x.length(); i++){
            char ch = x[i];
            
            if(ch == '[' || ch == '{' || ch == '('){
                stk.push(ch);
            }else{
                if(!stk.empty()){
                    char top_val = stk.top();
                    if(matches(top_val, ch)){
                       stk.pop(); 
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }
};
/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid 
strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a 
parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to 
be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Link : https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

Example 1:
    Input: s = "())"
    Output: 1

Example 2:
    Input: s = "((("
    Output: 3

Constraints:
    1 <= s.length <= 1000
    s[i] is either '(' or ')'.
*/

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if(ch == '('){
                stk.push(ch);
            }else{
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                }else{
                    stk.push(ch);
                }
            }
        }
        
        int count = 0;
        while(!stk.empty()){
            count++;
            stk.pop();
        }
        
        return count;
    }
};

// approach 2 : counting in the for loop itself.
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int count = 0;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if(ch == '('){
                stk.push(ch);
                count++;
            }else{
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                    count--;
                }else{
                    stk.push(ch);
                    count++;
                }
            }
        }
        return count;
    }
};

// For changing the open bracket to close bracket and 
// close bracket to open bracket instead of adding the bracket to
// make the expression valid, we can use below code.

// int openBracket = 0;
// int closeBracket = 0;
// while(!stk.empty()){
//     if(stk.top == '('){
//         openBracket++;
//     }else{
//         closeBracket++:
//     }

//     stk.pop();
// }

// return ((openBracket+1)/2 + (closeBracket+1)/2);
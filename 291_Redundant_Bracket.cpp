/*
Given valid mathematical expressions in the form of a string. You are 
supposed to return true if the given expression contains a pair of 
redundant brackets, else return false. The given string only contains 
‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

Note :
A pair of brackets is said to be redundant when a subexpression is 
surrounded by needless/ useless brackets.

Link : https://www.codingninjas.com/codestudio/problem-details/redundant-brackets_975473


Example 1:
((a+b)) has a pair of redundant brackets. The pair of brackets on the 
first and last index is needless. 
While (a + (b*c)) does not have any pair of redundant brackets. 

Constraints :
    1 <= T <= 50
    3 <= |S| <= 10^4

    Time Limit: 1 sec
*/

#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    int size = s.length();
    stack<char> ans;
    for(int i=0; i<size; i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            ans.push(ch);
        }else{
            if(ch == ')'){
                bool isRedundant = true;
                while(ans.top() != '('){
                    if(ans.top() == '+' || ans.top() == '-' || ans.top() == '*' || ans.top() == '/'){
                        isRedundant = false;
                    }
                    ans.pop();
                }
                if(isRedundant == true){
                    return true;
                }
               ans.pop();
            }
        }
    }
    return false;
}
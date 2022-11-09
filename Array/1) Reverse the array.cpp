/*
Write a program to reverse an array or string.
link : https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
 

Example 1:
  Input : Geeks
  Output: skeeG

Example 2:
  Input  : arr[] = {1, 2, 3}
  Output : arr[] = {3, 2, 1}

Constraints:
  1 <= |s| <= 10000

  Expected Time Complexity: O(|S|).
  Expected Auxiliary Space: O(1).

*/

#include<iostream>
using namespace std; 

string reverseWord(string str){
    
  int left = 0;
  int right = str.length()-1;
  
  while(left <= right){
    swap(str[left], str[right]);
    left++;
    right--;
  }
  
  return str;
}

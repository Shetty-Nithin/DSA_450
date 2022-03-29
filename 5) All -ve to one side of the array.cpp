/*
Move all negative numbers to beginning and positive to end with constant extra space.
Link : https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

Example :
    Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
    Output: -12 -13 -5 -7 -3 -6 11 6 5

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reArrange(int arr[], int size){
    int index = 0;
	for(int i=0; i<size; i++){
	    if(arr[i] < 0){
            if(i != index){
	     	    swap(arr[i], arr[index]);
            }
	     	index++;
	    }
	}
}

int main() {
    int arr[] = { 5,4,3,2,1,0,-1,-2,-3,-4,-5};
    int size = 11;
    
    reArrange(arr, size);
	
	for(int i=0; i<size; i++){
	    cout << arr[i] << ", ";
	}
}
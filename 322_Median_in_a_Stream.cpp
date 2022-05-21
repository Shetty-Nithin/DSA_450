/*
Given an input stream of N integers. The task is to insert these numbers
into a new stream and find the median of the stream formed by each 
insertion of X to the new stream.

Link : https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
Link : https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268

Example 1:
    Input:
    N = 4
    X[] = 5,15,1,3

    Output:
    5
    10
    5
    4

    Explanation:Flow in stream : 5, 15, 1, 3 
    5 goes to stream --> median 5 (5) 
    15 goes to stream --> median 10 (5,15) 
    1 goes to stream --> median 5 (5,15,1) 
    3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:
    Input:
    N = 3
    X[] = 5,10,15

    Output:
    5
    7.5
    10

    Explanation:Flow in stream : 5, 10, 15
    5 goes to stream --> median 5 (5) 
    10 goes to stream --> median 7.5 (5,10) 
    15 goes to stream --> median 10 (5,10,15) 

 
Constraints:
    1 <= N <= 10^6
    1 <= x <= 10^6

    Expected Time Complexity : O(nlogn)
    Expected Auxilliary Space : O(n)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int signum(int maxiSize, int miniSize){
	if(maxiSize == miniSize){
		return 0;
	}else if(maxiSize > miniSize){
		return 1;
	}else{
		return -1;
	}
}

void callMedian(int element, priority_queue<int> &maxi,
			   priority_queue<int, vector<int>, greater<int>> &mini, int &median){
	
    switch(signum(maxi.size(), mini.size())){

		case 0: if(element > median){
					mini.push(element);
					median = mini.top();
				}else{
					maxi.push(element);
					median = maxi.top();
				}
				break;

		case 1: if(element > median){
					mini.push(element);
					median = (mini.top() + maxi.top())/2;
				}else{
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				break;

		case -1: if(element > median){
					maxi.push(mini.top());
					mini.pop();
					mini.push(element);
					median = (mini.top() + maxi.top())/2;
				}else{
					maxi.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int> ans;
	priority_queue<int> max_Heap;
	priority_queue<int, vector<int>, greater<int>> min_Heap;
	int median = 0;
	
	for(int i=0; i<n; i++){
		callMedian(arr[i], max_Heap, min_Heap, median);
		ans.push_back(median);
	}
	return ans;
}


/*
Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him
since he has a nifty new woodcutting machine that can take down forests like
wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres),
and the machine raises a giant sawblade to that height and cuts off all tree
parts higher than H (of course, trees not higher than H meters remain intact).
Mirko then takes the parts that were cut off. For example, if the tree row
contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises
his sawblade to 15 metres, the remaining tree heights after cutting will be
15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off
the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than
necessary. That‟s why he wants to set his sawblade as high as possible.
Help Mirko find the maximum integer height of the sawblade that still allows
him to cut off at least M metres of wood.

Link : https://www.spoj.com/problems/EKO/

Example 1:
    Input:
    4 7
    20 15 10 17

    Output:
    15

Example 2:
    Input:
    5 20
    4 42 40 26 46

    Output:
    36
*/

#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isPossible(vector<long long int>& trees, long long int m, long long int mid){
	long long int woodCollected = 0;
	for(int i=0; i<trees.size(); i++){
		if(trees[i]>mid){
			woodCollected += trees[i]-mid;
		}
	}
	
	return (woodCollected >= m);
}

long long int maxSawBladeHeight(vector<long long int>& trees, long long int m){
	long long int start = 0, end, mid, ans = -1;
	end = *max_element(trees.begin(), trees.end());
	
	while(start <= end){
		mid = start + (end-start)/2;
		if(isPossible(trees, m, mid)){
			ans = mid;
			start = mid+1;
		}
		else end = mid-1;
	}
	return ans;
}

int main() {
	long long int n, m;
	cin >> n >> m;
	vector<long long int> trees;
	while(n--){
		long long int height;
		cin >> height;
		trees.push_back(height);
	}
	
	cout << maxSawBladeHeight(trees, m) << endl;
    return 0;
}
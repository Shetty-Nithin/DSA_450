/*
IEEE is having its AGM next week and the president wants to serve cheese prata
after the meeting. The subcommittee members are asked to go to food connection
and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50)
and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the
first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and
so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he
will cook one prata in 2 minutes one more prata in the next 4 mins an one more in
the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also
he can cook only 3 pratas as he does not have enough time for the 4th prata).
The webmaster wants to know the minimum time to get the order done. Please write
a program to help him out.

Link : https://www.spoj.com/problems/PRATA/ 

Example 1:
    Input:
        3
        10
        4 1 2 3 4
        8
        1 1
        8
        8 1 1 1 1 1 1 1 1

    Output:
        12
        36
        1
*/

#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& cooksRanks, int nP, int mid){
	int currP = 0;
	for(int i=0; i<cooksRanks.size(); i++){
		int R = cooksRanks[i];
		int j=1;
		int timeTaken = 0;
		
		while(true){ 
			if(timeTaken+(j*R) <= mid){
				timeTaken += (j*R);
				j++;
				currP++; 
			}
			else break;
		}
		if(currP >= nP) return true;
	}
	return false;
}

int minTimetToCompleteOrder(vector<int> &cooksRanks, int nP){
	int start = 0;
	int highestRanker = *max_element(cooksRanks.begin(), cooksRanks.end());
	int end = highestRanker * (nP *(nP+1))/2;
	int ans = -1;
	
	while(start <= end){
		int mid = start + (end-start)/2;
		if(isPossible(cooksRanks, nP, mid)){
			ans = mid;
			end = mid-1;
		}
		else start = mid+1;
	}
	return ans;
}

int main() {
	int T; cin >> T;
	
	while(T--){
		int nP, nC;
		cin >> nP >> nC;
		
		vector<int> cooksRanks;
		while(nC--){
			int R; cin >> R;
			cooksRanks.push_back(R);
		}
		
		cout << minTimetToCompleteOrder(cooksRanks, nP) << endl;
	}
	return 0;
}
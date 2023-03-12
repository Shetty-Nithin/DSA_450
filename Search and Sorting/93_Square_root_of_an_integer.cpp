/*
Find the nearest square root of a given interger.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int squareRoot(int N) {
        if(N==0 || N==1){
            return N;
        }
        
        int start = 1;
        int end = N;
        int ans;
        
        while(start <= end){
            int mid = (start+end)/2;

            if(mid*mid == N) return mid;
            if(mid*mid < N){
                start = mid+1;
                ans = mid;
            }
            else{
                end = mid-1;
            }
        }
        
        return ans;
    }
};
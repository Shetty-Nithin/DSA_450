/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than
two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.
Link : https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

Example 1:
    Input:
    N=3,  K=2 
    Output: 6

Example 2:
    Input:
    N=2,  K=4
    Output: 16

Constraints:
    1 ≤ N ≤ 5000
    1 ≤ K ≤ 100
    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Approach 1 : Recurssion
class Solution1{
    private:
        long long add(int a, int b){
            return ((a%MOD) + (b%MOD))%MOD;
        }
        
        long long mul(int a, int b){
            return ((a%MOD) * (b%MOD))%MOD;
        }
        
        long long countWaysUtil(int n, int k){
            if(n == 1){
                return k;
            }
            if(n == 2){
                return add(k, mul(k, k-1));
            }
            
            return add(mul(countWaysUtil(n-2, k), k-1), mul(countWaysUtil(n-1, k), k-1));
        }
    public:
    long long countWays(int n, int k){
        return countWaysUtil(n, k);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution2{
    private:
        long long add(long long a, long long b){
            return ((a%MOD) + (b%MOD))%MOD;
        }
        
        long long mul(long long a, long long b){
            return ((a%MOD) * (b%MOD))%MOD;
        }
        
        long long countWaysUtil(int n, int k, vector<long long> &dp){
            if(n == 1){
                return k;
            }
            if(n == 2){
                return add(k, mul(k, k-1));
            }
            
            if(dp[n] != -1){
                return dp[n];
            }
            
            dp[n] = add(mul(countWaysUtil(n-2, k, dp), k-1), mul(countWaysUtil(n-1, k, dp), k-1));
            return dp[n];
        }
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1, -1);
        return countWaysUtil(n, k, dp);
    }
};

// Approach 3 : Bottoms-Up/Tabulation
class Solution3{
    private:
        long long add(long long a, long long b){
            return ((a%MOD) + (b%MOD))%MOD;
        }
        
        long long mul(long long a, long long b){
            return ((a%MOD) * (b%MOD))%MOD;
        }
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1, 0);
        dp[1] = k;
        dp[2] = add(k, mul(k, k-1));
        
        for(int i=3; i<=n; i++){
            dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
        }
        return dp[n];
    }
};

// Approach 4 : Bottoms-Up/Tabulation with space optimization (working fine in coding ninja)
class Solution4{
    private:
        long long add(long long a, long long b){
            return ((a%MOD) + (b%MOD))%MOD;
        }
        
        long long mul(long long a, long long b){
            return ((a%MOD) * (b%MOD))%MOD;
        }
    public:
    long long countWays(int n, int k){
        long long prev2 = k;
        long long prev1 = add(k, mul(k, k-1));
        
        for(int i=3; i<=n; i++){
            long long ans = add(mul(prev2, k-1), mul(prev1, k-1));
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};
/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in
the second lane and wants to jump to point n. However, there could be obstacles along the way.
You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle
on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i.
There will be at most one obstacle in the 3 lanes at each point.
For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at
point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane
(even if they are not adjacent) at the same point if there is no obstacle on the new lane.
For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.
Note: There will be no obstacles on points 0 and n.
Link : https://leetcode.com/problems/minimum-sideway-jumps/

Example 1:
    Input: obstacles = [0,1,2,3,0]
    Output: 2 
    Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
                 Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).

Example 2:
    Input: obstacles = [0,1,1,3,3,0]
    Output: 0
    Explanation: There are no obstacles on lane 2. No side jumps are required.

Example 3:
    Input: obstacles = [0,2,1,0,3,0]
    Output: 2
    Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.

Constraints:
    obstacles.length == n + 1
    1 <= n <= 5 * 105
    0 <= obstacles[i] <= 3
    obstacles[0] == obstacles[n] == 0
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Apporach 1 : Recurssion
class Solution {
private:
    int minSideJumpsUtil(vector<int>& obstacles, int point, int lane){
        if(point+1 >= obstacles.size()){
            return 0;
        }

        if(obstacles[point+1] != lane){
            return minSideJumpsUtil(obstacles, point+1, lane);
        }
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(lane != i && obstacles[point] != i){
                    ans = min(ans, 1 + minSideJumpsUtil(obstacles, point+1, i));
                }
            }
            return ans;
        }
    }  
public:
    int minSideJumps(vector<int>& obstacles) {
        return minSideJumpsUtil(obstacles, 0, 2);
    }
};

// Apporach 2 : Recurssion + Memoization
class Solution {
private:
    int minSideJumpsUtil(vector<int>& obstacles, int point, int lane, vector<vector<int>>& dp){
        if(point+1 >= obstacles.size()){
            return 0;
        }

        if(dp[lane][point] != -1){
            return dp[lane][point];
        }

        if(obstacles[point+1] != lane){
            return minSideJumpsUtil(obstacles, point+1, lane, dp);
        }
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(lane != i && obstacles[point] != i){
                    ans = min(ans, 1 + minSideJumpsUtil(obstacles, point+1, i, dp));
                }
            }
            dp[lane][point] = ans;
            return dp[lane][point];
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return minSideJumpsUtil(obstacles, 0, 2, dp);
    }
};

// Apporach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n+1, 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int point=n-1; point>=0; point--){
            for(int lane=1; lane<=3; lane++){
                if(obstacles[point+1] != lane){
                    dp[lane][point] = dp[lane][point+1];
                }
                else{
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(lane != i && obstacles[point] != i){
                            ans = min(ans, 1 + dp[i][point+1]);
                        }
                    }
                    dp[lane][point] = ans;
                }
            }
        }

        return min(dp[2][0], min(dp[1][0]+1, dp[3][0]+1));
    }
};

// Apporach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int point=n-1; point>=0; point--){
            for(int lane=1; lane<=3; lane++){
                if(obstacles[point+1] != lane){
                    curr[lane] = next[lane];
                }
                else{
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(lane != i && obstacles[point] != i){
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }

        return min(next[2], min(next[1]+1, next[3]+1));
    }
};
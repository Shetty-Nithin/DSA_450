/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied
by its satisfaction level i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
Link : https://leetcode.com/problems/reducing-dishes/

Example 1:
    Input: satisfaction = [-1,-8,0,5,-9]
    Output: 14
    Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to
                 (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.

Example 2:
    Input: satisfaction = [4,3,2]
    Output: 20
    Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
    Input: satisfaction = [-1,-4,-5]
    Output: 0
    Explanation: People do not like the dishes. No dish is prepared.

Constraints:
    n == satisfaction.length
    1 <= n <= 500
    -1000 <= satisfaction[i] <= 1000
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int maxSatisfactionUtil(vector<int>& satisfaction, int index, int time){
        if(index == satisfaction.size()){
            return 0;
        }

        int include = (satisfaction[index]*(time+1)) + maxSatisfactionUtil(satisfaction, index+1, time+1);
        int exclude = maxSatisfactionUtil(satisfaction, index+1, time);

        return max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return maxSatisfactionUtil(satisfaction, 0, 0);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int maxSatisfactionUtil(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp){
        if(index == satisfaction.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }

        int include = (satisfaction[index]*(time+1)) + maxSatisfactionUtil(satisfaction, index+1, time+1, dp);
        int exclude = maxSatisfactionUtil(satisfaction, index+1, time, dp);

        return dp[index][time] = max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return maxSatisfactionUtil(satisfaction, 0, 0, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                int include = (satisfaction[index]*(time+1)) + dp[index+1][time+1];
                int exclude = dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                int include = (satisfaction[index]*(time+1)) + next[time+1];
                int exclude = next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return curr[0];
    }
};
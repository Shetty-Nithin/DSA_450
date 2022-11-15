/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as
an integer array days. Each day is an integer from 1 to 365.
Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.
For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
Link : https://leetcode.com/problems/minimum-cost-for-tickets/

Example 1:
    Input: days = [1,4,6,7,8,20], costs = [2,7,15]
    Output: 11
    Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
                 On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
                 On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
                 On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
                 In total, you spent $11 and covered all the days of your travel.

Example 2:
    Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
    Output: 17
    Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
                 On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
                 On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
                 In total, you spent $17 and covered all the days of your travel.

Constraints:
    1 <= days.length <= 365
    1 <= days[i] <= 365
    days is in strictly increasing order.
    costs.length == 3
    1 <= costs[i] <= 1000
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recurssion
class Solution {
private:
    int mincostTicketsUtil(vector<int>& days, vector<int>& costs, int index){
        int n = days.size();
        if(index >= n){
            return 0;
        }

        int dayPass = costs[0] + mincostTicketsUtil(days, costs, index+1);

        int i;
        for(i=index; (i<n)&&(days[i]<days[index]+7); i++);
        int weekPass = costs[1] + mincostTicketsUtil(days, costs, i);

        for(i=index; (i<n)&&(days[i]<days[index]+30); i++);
        int monthPass = costs[2] + mincostTicketsUtil(days, costs, i);

        return min(dayPass, min(weekPass, monthPass));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTicketsUtil(days, costs, 0);
    }
};

// Approach 2 : Recurssion + Memoization
class Solution {
private:
    int mincostTicketsUtil(vector<int>& days, vector<int>& costs, int index, int n, vector<int> &dp){
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }
        // day pass
        int dayPass = costs[0] + mincostTicketsUtil(days, costs, index+1, n, dp);
        //weekly pass
        int i;
        for(i=index; (i<n)&&(days[i]<days[index]+7); i++);
        int weekPass = costs[1] + mincostTicketsUtil(days, costs, i, n, dp);
        // monthly pass
        for(i=index; (i<n)&&(days[i]<days[index]+30); i++);
        int monthPass = costs[2] + mincostTicketsUtil(days, costs, i, n, dp);

        dp[index] = min(dayPass, min(weekPass, monthPass));
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return mincostTicketsUtil(days, costs, 0, n, dp);
    }
};

// Approach 3 : Bottom-Up/Tabulation
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n] = 0;

        for(int k=n-1; k>=0; k--){
            int dayPass = costs[0] + dp[k+1];
            
            int i;
            for(i=k; (i<n)&&(days[i]<days[k]+7); i++);
            int weekPass = costs[1] + dp[i];
            
            for(i=k; (i<n)&&(days[i]<days[k]+30); i++);
            int monthPass = costs[2] + dp[i];

            dp[k] = min(dayPass, min(weekPass, monthPass));
        }

        return dp[0];
    }
};

// Approach 4 : Bottom-Up/Tabulation with space optimization
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        queue<pair<int, int>> month;
        queue<pair<int, int>> week;

        for(int day : days){
            //remove expired days
            while(!month.empty() && month.front().first + 30 <= day){
                month.pop();
            }
            while(!week.empty() && week.front().first + 7 <= day){
                week.pop();
            }

            // add cost for the current day
            week.push(make_pair(day, ans+costs[1]));
            month.push(make_pair(day, ans+costs[2]));

            ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }

        return ans;
    }
};
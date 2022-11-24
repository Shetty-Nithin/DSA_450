/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time
of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in
the meeting room at a particular time?
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

Example 1:
    Input:
    N = 6
    start[] = {1,3,0,5,8,5}
    end[] =  {2,4,6,7,9,9}
    Output: 
    4
    Explanation:
    Maximum four meetings can be held with
    given start and end timings.
    The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

Example 2:
    Input:
    N = 3
    start[] = {10, 12, 20}
    end[] = {20, 25, 30}
    Output: 
    1
    Explanation:
    Only one meetings can be held
    with given start and end timings.

Constraints:
    1 ≤ N ≤ 105
    0 ≤ start[i] < end[i] ≤ 10^5
    Expected Time Complexity : O(N*LogN)
    Expected Auxilliary Space : O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool static comparator(pair<int, int> schedule_1, pair<int, int> schedule_2){
    if(schedule_1.second < schedule_2.second){
        return true;
    }
    return false;
} 

int maxMeetings(int s[], int e[], int n)
{
    vector<pair<int, int>> scheduleArr;
    
    for(int i=0; i<n; i++){
        scheduleArr.push_back({s[i], e[i]});
    }
    
    sort(scheduleArr.begin(), scheduleArr.end(), comparator);
    
    int count = 0;
    int limit = scheduleArr[0].second;
    count++;
    
    for(int i=1; i<n; i++){
        if(scheduleArr[i].first > limit){
            limit = scheduleArr[i].second;
            count++;
        }
    }
    
    return count;
}
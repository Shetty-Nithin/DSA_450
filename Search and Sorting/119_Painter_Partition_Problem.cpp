/*
Dilpreet wants to paint his dog's home that has n boards with different lengths. 
The length of ith board is given by arr[i] where arr[] is an array of n integers.
He hired k painters for this work and each painter takes 1 unit time to paint 1 
unit of the board. 

The problem is to find the minimum time to get this job done if all painters start 
together with the constraint that any painter will only paint continuous boards, 
say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

Link : https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

Example 1:
    Input:
        n = 5
        k = 3
        arr[] = {5,10,30,20,15}
    Output: 35
    Explanation: The most optimal way will be:
        Painter 1 allocation : {5,10}
        Painter 2 allocation : {30}
        Painter 3 allocation : {20,15}
        Job will be done when all painters finish
        i.e. at time = max(5+10, 30, 20+15) = 35

Example 2:
    Input:
        n = 4
        k = 2
        arr[] = {10,20,30,40}
    Output: 60
    Explanation: The most optimal way to paint:
        Painter 1 allocation : {10,20,30}
        Painter 2 allocation : {40}
        Job will be complete at time = 60

Constraints:
    Expected Time Complexity: O(n log m) , m = sum of all boards' length
    Expected Auxiliary Space: O(1)

    1 ≤ n ≤ 105
    1 ≤ k ≤ 105
    1 ≤ arr[i] ≤ 105
*/
class Solution
{
  private:
    bool isPossible(int arr[], int n, int k, long long mid){
        long long currUnits = 0;
        long long painters = 1;
        for(int i=0; i<n; i++){
            if(currUnits+arr[i] <= mid){
                currUnits += arr[i];
            }
            else{
                painters++;
                currUnits = arr[i];
                if(painters > k || arr[i] > mid){
                    return false;
                }
            }
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long start = 0;
        long long end = 0;
        for(int i=0; i<n; i++){
            end += arr[i];
        }
        long long ans = -1;
        
        long long mid = start + (end-start)/2;
        while(start <= end){
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        
        return ans;
    }
};
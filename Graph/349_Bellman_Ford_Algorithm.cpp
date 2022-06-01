/*
Given a weighted directed graph with n nodes and m edges. Nodes are 
labeled from 0 to n-1, the task is to check if it contains a negative 
weight cycle or not.
Note: edges[i] is defined as u, v and weight.

Link : https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
Link : https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977

Example 1:
    Input: n = 3, edges = {{0,1,-1},{1,2,-2},
    {2,0,-3}}
    Output: 1
    Explanation: The graph contains negative weight
    cycle as 0->1->2->0 with weight -1,-2,-3.

Example 2:
    Input: n = 3, edges = {{0,1,-1},{1,2,-2},
    {2,0,3}}
    Output: 0
    Explanation: The graph does not contain any
    negative weight cycle.

Constraints:
    1 <= n <= 100
    1 <= m <= n*(n-1), 
    where m is the total number of Edges in the directed graph.

    Expected Time Complexity: O(n*m)
    Expected Space Compelxity: O(n)
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }
    
    //check for negative cycle
    bool flag = false;
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
            flag = true;
        }
    }
    
    if(flag == false){
        return dist[dest];
    }
    return -1;
    
}

/*
Given a weighted directed graph with n nodes and m edges. Nodes are 
labeled from 0 to n-1, the task is to check if it contains a negative 
weight cycle or not.
Note: edges[i] is defined as u, v and weight.

Link : https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

You have been given a directed weighted graph of ‘N’ vertices labeled from 
1 to 'N' and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 
'w' denoting the distance between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’
vertex given to you in the graph. The graph may contain negatively weighted edges.

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
    Expected Space Compel xity: O(n)
*/



/**
 * Bellman Ford Algorithm can apply on directed graph with negative values
 * but not negative cycle.
 * 
 * If the graph is undirected, then we need to convert into directed first,
 * to apply the Bellman Ford algorithm.
 */


/**
 * In Bellman Ford Algorithm we need to apply the below formula for (n-1) times
 * on all the edges
 * (u -> v)
 * Formula : (dist[u] + w) < dist[v]
 * 
 * The reason why (n-1) time is : Shortest distance path can be the one
 * with max number of edges. And the max possible number of edges, a shortest
 * path can have is (n-1).
 * 
 * After applying the above formula for (n-1) times, apply one more time.
 * If now any of the distance is updated, then it means negative cycle is 
 * present and not possible to find the shortest path and return -1 else
 * return the array of shortest path.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e9); // initializing the distance with the max value.
    dist[src] = 0; // source to source distance is 0.    

    // apply the equation on "m" number of edges for "n-1" times  
    for(int i=1; i<=n; i++){ // n = vertices
        for(int j=0; j<m; j++){ // m = edges = {{x,y,z},{x,y,z},...}
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
            // break;
        }
    }
    
    if(flag == false){
        return dist[dest]; // this is the shortest paht between the give source and destination.
    }
    return -1; // cycle is present, hence cannot find the shortest path between the given source and the destination.
    
}

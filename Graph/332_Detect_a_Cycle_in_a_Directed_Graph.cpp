/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and 
E edges, check whether it contains any cycle or not.

Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/
Link : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

Example 1:
    Input:
         0 -----> 1
                  |
                  ^
       --3 <----- 2
       |  ^
       |__|

    Output: 1
    Explanation: 3 -> 3 is a cycle

Example 2:
    Input:
         0 -----> 1
                  |
                  ^
                  2

    Output: 0
    Explanation: no cycle in the graph



Constraints:
    1 ≤ V, E ≤ 10^5

    Expected Time Complexity: O(V + E)
    Expected Auxiliary Space: O(V)
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/**
  * Using DFS Algorithm
  **/
class Solution {
  public:
    bool dfs(int node, vector<bool> &visited, vector<bool> &dfs_visited,
            vector<int> adj[]){
                
            visited[node] = true;
            dfs_visited[node] = true;
            // dfs_visited  = true means, call is in progress.
            // dfs_visited = false means, cal has not been called yet.

            // If n the node does not have any adjacent node or no cycle 
            // found which include this node, then dfs_visited[node] 
            // will become false. And the same process will repeat if
            // there are any nodes remaining in the graph else returns false.
            
            for(auto neighbour : adj[node]){
                if(!visited[neighbour]){
                    if(dfs(neighbour, visited, dfs_visited, adj)){
                        return true;
                    }
                }else if(dfs_visited[neighbour]){ // dfs_visited[neighbour] = true from the other way of the cyclic path.
                    return true;                  // so cycle is present.
                }
            }
            
            dfs_visited[node] = false; // back tracking
            return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, 0);
        vector<bool> dfs_visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, visited, dfs_visited, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};



/**
  * Using BFS Algorithm and Kahn's Algorithm
  **/

 int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {   
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        
        adjList[u].push_back(v); // directed graph
    }
    
    // Find all indegrees
    vector<int> inDegree(n);
    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    
    // Push '0' inDegree to the queue
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    // BFS
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        count++;
        
        for(auto neighbour: adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(count == n){
        return false; // In topological sort cycle will not be present.
    }else{
        return true; // This is invalid topological sort because of cycle.
    }
}
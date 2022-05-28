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


bool checkCycleDFS(int node, unordered_map<int, bool> &visited, 
                   unordered_map<int, bool> &dfs_visited, 
                   unordered_map<int, list<int>> &adjList){
    
    visited[node] = true;
    dfs_visited[node] = true;
    
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfs_visited, adjList);
            if(cycleDetected){
                return true;
            }
        }else if(dfs_visited[neighbour]){
            return true;
        }
    }
    dfs_visited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {   
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }
    
    // calling DFS for all the components.
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfs_visited;
    for(int i=1; i<=n; i++){
       if(!visited[i]){
           bool cycleFound = checkCycleDFS(i, visited, dfs_visited, adjList);
           if(cycleFound){
               return true;
           }
       } 
    }
    return false;
}



/**
  * Using BFS Algorithm and Kahn's Algorithm
  **/

 int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {   
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        
        adjList[u].push_back(v);
    }
    
    //find all indegrees
    vector<int> inDegree(n);
    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    
    // push '0' inDegree
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
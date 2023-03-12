/*
Given an undirected and disconnected graph G(V, E), containing 'V' vertices
and 'E' edges, the information about edges is given using 'GRAPH' matrix, 
where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS 
traversal.

Link : https://www.codingninjas.com/codestudio/problem-details/dfs-traversal_630462

Example 1:
    Input:
    5 4
    0 2
    0 1
    1 2
    3 4
    Output:
    2
    0 1 2
    3 4

Constraints :
    2 <= V <= 10^3
    1 <= E <= (5 * (10^3))

    Time Limit: 1sec
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, 
         unordered_map<int, list<int>> &adjList, vector<int> &component){
    component.push_back(node);
    visited[node] = true;
    
    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component; // this is becuse of return type.
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    
    return ans;
}
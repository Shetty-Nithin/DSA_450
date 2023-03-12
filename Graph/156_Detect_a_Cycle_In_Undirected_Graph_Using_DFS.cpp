// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Link : https://www.codingninjas.com/codestudio/problem-details/cycle-detection-in-undirected-graph_1062670

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited,
                unordered_map<int, list<int>> &adjList){
    
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);
            if(cycleDetected){
                return true;
            }
        }else if(neighbour != parent){ // visited and its not a parent
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}

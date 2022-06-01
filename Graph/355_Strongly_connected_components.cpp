// Kosaraju's Alogrithm

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E 
edges, Find the number of strongly connected components in the graph.

Link : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

Constraints:
    1 ≤ V ≤ 5000
    0 ≤ E ≤ (V*(V-1))
    0 ≤ u, v ≤ N-1
    Sum of E over all testcases will not exceed 25*10^6
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st,
        unordered_map<int, list<int>> &adjList){
    
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(neighbour, visited, st, adjList);
        }
    }
    st.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, 
           unordered_map<int, list<int>> &adjList){
    
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            revDFS(neighbour, visited, adjList);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adjacency list
	unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    //topological sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, visited, st, adjList);
        }
    }
    
    //create a transpose of graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++){
        visited[i] = 0;
        for(auto neighbour : adjList[i]){
            transpose[neighbour].push_back(i);
        }
    }
    
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        if(!visited[top]){
            count++;
            revDFS(top, visited, transpose);
        }
    }
    
    return count;
}
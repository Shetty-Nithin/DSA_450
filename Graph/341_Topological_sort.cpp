/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, 
Find any Topological Sorting of that Graph.

Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
Link : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

Example 1:
    Input:
         1 
          \
           \
            0 <-------- 3
           ^
          /
         /
        2
    Output:
    1

    Explanation:
    The output 1 denotes that the order is valid. So, if you have, 
    implemented your function correctly, then output would be 1 for all 
    test cases. One possible Topological order for the graph is 3, 2, 1, 0.

Example 2:
    Input:
           0 <--------- 4
        /                \
      5                   \
      \                    1
       2                  /
        \------>3<-------/



    Output:
    1

    Explanation:
    The output 1 denotes that the order is valid. So, if you have, 
    implemented your function correctly, then output would be 1 for all 
    test cases. One possible Topological order for the graph is 5, 4, 2, 1, 3, 0.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**
 * Using DFS Algorithm
 * 
 */
void topologicalSort(int node, vector<bool> &visited,
                    stack<int> &stk, unordered_map<int, list<int>> &adjList){
    visited[node] = 1;
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            topologicalSort(neighbour, visited, stk, adjList);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    //cal DFS topological sort util funciton for all the components
    vector<bool> visited(v);
    stack<int> stk;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topologicalSort(i, visited, stk, adjList);
        }
    }
    
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    
    return ans;
}



/**
 * Using Kahn's Algorithm or jBFS Algorithm
 * 
 */
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    //find all indegrees
    vector<int> inDegree(v);
    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    
    // push '0' inDegree
    queue<int> q;
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    // BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto neighbour: adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}
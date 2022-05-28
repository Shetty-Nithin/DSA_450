/*
Given an undirected graph with V vertices and E edges, check whether 
it contains any cycle or not. 

Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
Link : https://www.codingninjas.com/codestudio/problem-details/cycle-detection-in-undirected-graph_1062670

Example 1:
    Input:   
         0 _______1 _______ 2
                   \         \
                    \         3
                     4 ______/      
    Output: 1
    Explanation: 1->2->3->4->1 is a cycle.

Example 2:
    Input: 
             0
        1 ________2
                 /
             3__/
    Output: 0
    Explanation: No cycle in the graph.

Constraints:
    1 ≤ V, E ≤ 10^5

    Expected Time Complexity: O(V + E)
    Expected Space Complexity: O(V)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

/*
 * Using BFS Algorithm
 */

bool isCyclicBFS(int src, unordered_map<int, bool> &visited,
                unordered_map<int, list<int>> &adjList){
    unordered_map<int, int> parent;
    queue<int> q;

    parent[src] = -1;
    visited[src] = 1;
    q.push(src);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour : adjList[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //to handle disconnected component
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adjList);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}


/*
 * Using DFS Algorithm
 */

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited,
                unordered_map<int, list<int>> &adjList){
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);
            if(cycleDetected){
                return true;
            }
        }else if(neighbour != parent){
                return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //to handle disconnected component
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

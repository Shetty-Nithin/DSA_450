/*
Given a directed graph. The task is to do Breadth First Traversal of 
this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from 
u to v and find the BFS traversal of the graph starting from the 0th 
vertex, from left to right according to the graph. Also, you should 
only take nodes directly or indirectly connected from Node 0 in 
consideration.

Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
Link : https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

Example 1:
    Input:

    Output: 0 1 2 3 4

    Explanation: 
    0 is connected to 1 , 2 , 3. 
    2 is connected to 4.
    so starting from 0, it will go to 1 then 2 then 3.
    After this 2 to 4, thus bfs will be 0 1 2 3 4.

Example 2:
    Input:

    Output: 0 1 2
    Explanation:
    0 is connected to 1 , 2.
    so starting from 0, it will go to 1 then 2, thus bfs will 
    be 0 1 2 3 4. 



Constraints:
    1 ≤ V, E ≤ 10^4

    Expected Time Complexity: O(V + E)
    Expected Auxiliary Space: O(V)

*/
// was getting TLE on submittin.

#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs_fun(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited,
             vector<int> &ans, int node){        
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    prepareAdjList(adjList, edges);
    
    //this for loop is for disconnect graphs.
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs_fun(adjList, visited, ans, i);
        }
    }
    return ans;
}

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

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
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
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}
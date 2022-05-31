/*
You are given an undirected connected weighted graph having ‘N’ nodes 
numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which 
represents the ‘M’ edges such that there is an edge directed from 
node E[i][0] to node E[i][1]. You are supposed to return the minimum 
spanning tree where you need to return weight for each edge in the MST.

Link : https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633


Example 1:
    input: 
            1
       5  / | \  15
         /  |  \
        0   |10 3
         \  |  /
       8  \ | /  20
            2

    ouput:
            1
       5  /   \  15
         /     \
        0       3
         \    
       8  \   
            2

Constraints :
    1 ≤ T ≤ 5
    2 <= N <= 100
    1 <= M <= min(1000, N(N - 1) / 2)
    1 <= E[i][0], E[i][1] <= N

    Time Limit: 1 sec
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;
        
        for(int v=1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        
        mst[u] = true;
        
        for(auto it : adjList[u]){
            int v = it.first;
            int w = it.second;
            
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++){
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    
    return result;
}

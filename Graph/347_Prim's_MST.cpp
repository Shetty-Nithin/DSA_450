/*
You are given an undirected connected weighted graph having ‘N’ nodes 
numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which 
represents the ‘M’ edges such that there is an edge directed from 
node E[i][0] to node E[i][1]. You are supposed to return the minimum 
spanning tree where you need to return weight for each edge in the MST.

Link : https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633
Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

(Converting graph into tree with N node and N-1 edges, so that any node can be 
reachable from any other node)

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

Example 2:
    input:
    0 ------ 1 ------ 2
    |      / |      /
    |    /   |    /
    |  /     |  /
     3       4

     output:
    0 ------ 1 ------ 2
    |        |      
    |        |    
    3        4
Constraints :
    1 ≤ T ≤ 5
    2 <= N <= 100
    1 <= M <= min(1000, N(N - 1) / 2)
    1 <= E[i][0], E[i][1] <= N

    Time Limit: 1 sec
*/

// Intuition is updating minimum distance to the parent from the current node and
// creating the graph, which leads to MST.
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
    // (n+1) : to match node and index
    vector<int> weight(n+1); // weight[1] is the weight between 0 and 1
    vector<bool> mst(n+1); 
    vector<int> parent(n+1);
    
    for(int i=0; i<=n; i++){
        weight[i] = INT_MAX; // considering the max weight initially
        mst[i] = false; // no node is belong to MST initially
        parent[i] = -1;
    }
    weight[1] = 0;
    parent[1] = -1; //considering 1 as source node
    
    for(int i=1; i<n; i++){
        int minWeight = INT_MAX;
        int u;
        
        // finding the min weight in the weight array.
        for(int v=1; v<=n; v++){
            if(mst[v] == false && weight[v] < minWeight){
                u = v; // assigning minimum value in the weight array to "u"
                minWeight = weight[v]; // updating the minimum value
            }
        }
        mst[u] = true;
        
        for(auto neighbour : adjList[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            
            // Here it is checking which parent has the min weight from "v"
            // is it the already existing parent or current parent i.e., "u"?
            if(mst[v] == false && w < weight[v]){
                weight[v] = w;
                parent[v] = u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    //since parent of first node is -1, we cannot start from 1. Hence we are
    //starting from the 2nd node. (first node will be included as parent of second node)
    for(int i=2; i<=n; i++){
        result.push_back(make_pair(make_pair(parent[i], i), weight[i]));
    }
    
    return result;
}

/*
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1)
and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight 
denoting the distance between node ‘X’ and node ‘Y’.
Your task is to find the shortest path distance from the source node, 
which is the node labeled as 0, to all vertices given in the graph.

Link : https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469
Link : https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

Example 1:
    Input:
    5 7
    0 1 7
    0 2 1
    0 3 2
    1 2 3
    1 3 5 
    1 4 1
    3 4 7

    Output: 
    0 4 1 2 5


Example 2:
    Input:
    4 5
    0 1 5
    0 2 8
    1 2 9
    1 3 2
    2 3 6

    Output: 
    0 5 8 7

Constraints:
    1 <= T <= 50
    1 <= V <= 1000
    1 <= E <= 3000
    0 <= X, Y < V
    1 <= DISTANCE[X][Y] <= 10^5

    Time limit: 1 sec
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));
    
    while(!st.empty()){
        auto top = *(st.begin());
        
        int nodeDist = top.first;
        int topNode = top.second;
        st.erase(st.begin()); //removing the top node
        
        for(auto neighbour : adjList[topNode]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if(record != st.end()){
                    st.erase(record);
                }
                
                dist[neighbour.first] = nodeDist + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

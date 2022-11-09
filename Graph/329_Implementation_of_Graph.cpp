/*
You are given an undirected graph of 'N' nodes and 'M' edges. Your task 
is to create the graph and print the adjacency list of the graph. It is 
guaranteed that all the edges are unique, i.e., if there is an edge 
from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice 
versa. Also, there are no self-loops present in the graph.
In graph theory, an adjacency list is a collection of unordered lists 
used to represent a finite graph. Each list describes the set of 
neighbors of a vertex in the graph.

Link : https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551

Example 1:
    input : 
    1 2
    0 3
    2 3
    3 3
    Output 1:
    0 -> 3
    1 -> 2
    2 -> 1 3
    3 -> 0 2
    
Example 2:
    input : 
    0 1
    1 2
    2 0
    Output 1:
    0 -> 1 2
    1 -> 0 2
    2 -> 0 1

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//Problem from Coding Ninjas

// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     vector<int> ans[n];
    
//     for(int i=0; i<m; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];
//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }

//     /*
//      0  [[3],
//      1   [2],
//      2   [1, 3],
//      3   [0, 2]]
    
 
//      */
//     vector<vector<int>> adj(n);
//     for(int i=0; i<n; i++){
//         adj[i].push_back(i);
        
//         for(int j=0; j<ans[i].size(); j++){
//             adj[i].push_back(ans[i][j]);
//         }
//     }
//     return adj;
// }

// ---------------------Implementation-------------------------------
template <typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        // direction = 0 -> undirected graph;
        // direction = 1 -> directed graph;

        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout << i.first << "->";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){

    int n;
    cout << "enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "enter the edges" << endl;
    cin >> m;

    Graph<int> g;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
}
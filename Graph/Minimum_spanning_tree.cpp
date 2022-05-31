/*
You are given an undirected, connected and weighted graph G(V, E), 
consisting of V number of vertices (numbered from 0 to V-1) and E 
number of edges.
Find and print the total weight of the Minimum Spanning Tree (MST) 
using Kruskal's algorithm.
By definition, a minimum weight spanning tree is a subset of the edges
of a connected, edge-weighted undirected graph that connects all the
vertices together, without any cycles and with the minimum possible 
total edge weight.

Link : https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769

Example :
    input:
    4 4
    0 1 3
    0 3 5
    1 2 1
    2 3 8

    output: 
    9

Constraints :
    2 <= V <= 10^5
    1 <= E <= 3 * 10^5
    0 <= X < N
    0 <= Y < N
    1 <= W <= 10^4

    where V and E represent the number of vertices and edges respectively.
    X and Y represent the vertices between which there is an edge.
    W is the weight of the edge.

    Time limit: 1sec
*/

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
// for comparator
using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), comp);
    vector<int> parent(n);
    vector<int> rank(n);
    int minWeight = 0;
    
    makeSet(parent, rank, n);
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        if(u != v){
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}
/*
The city of Ninjaland is analogous to the unweighted graph. The city has
 ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M 
 bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ 
 which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed 
 that you can reach any house from any other house via some combination 
 of roads. Two houses are directly connected by at max one road.
A path between house ‘S’ to house ‘T’ is defined as a sequence of 
vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending 
house is ‘T’ and there is a road connecting two consecutive houses. 
Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you 
have to find the shortest path from ‘S’ to ‘T’.

Link : https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0


Example 1:
    input:
             2 ________ 5 ____
            /                 \
           /                   \
          1 ______ 3 __________ 8
           \                   /
            \                 /
             4 _____ 6 _____7
    output:
       (1, 3, 8)


Constraints :
    1 <= T <= 100
    2 <= N <= 10 ^ 3
    1 <= M <= min( N *(N - 1) / 2 , 1000 )
    1 <= S, T <= N

    Time Limit: 1 sec
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto i:adjList[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    
    // Prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
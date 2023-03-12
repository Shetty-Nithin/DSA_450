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
        
        adjList[u].push_back(make_pair(v, w)); // map( u : list{[first, second],[first, second],...} )
        adjList[v].push_back(make_pair(u, w)); // map( v : list{[first, second],[first, second],...} )
    }
    
    // distance from node '0' to every other node is taken as INT_MAX initially.
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0; // By default '0' is considered as a source. And the distance betwen 0 to 0 is 0.

           // dist, node
    set<pair<int, int>> st; // to keep in sorted order.
    st.insert(make_pair(0, source));
    
    while(!st.empty()){
        auto top = *(st.begin());
        st.erase(st.begin()); //removing the begining node (like queue in BFS)
        
        int nodeDist = top.first;
        int topNode = top.second;
                 //(v, w)
        for(auto neighbour : adjList[topNode]){
            // updating the smallest distance from cucrent node to its neighbour node.
            if(nodeDist + neighbour.second < dist[neighbour.first]){ // if current dist is less than existing dist

            // ------------ [Optional] --------------
                //checking if the node neighbour is alreday exists the set.
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                
                //deleting the existing entry of the node neighbour from the set.
                //The reason is already existing data's distance will be more than the current dist.
                // And comparing with this out dated entry is no use.
                if(record != st.end()){
                    st.erase(record);
                }
            // ------------ [Optional] --------------

                dist[neighbour.first] = nodeDist + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
 
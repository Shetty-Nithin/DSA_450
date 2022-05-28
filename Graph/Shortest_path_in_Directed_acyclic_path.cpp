#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Graph {
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addAdj(int u, int v, int weight){
            pair<int, int> p = make_pair(v, weight);
            adjList[u].push_back(p);
        }

        void dfs(int node, unordered_map<int, bool> &visited, stack<int> &stk){
            visited[node] = true;

            for(auto neighbour : adjList[node]){
                if(!visited[neighbour.first]){
                    dfs(neighbour.first, visited, stk);
                }
            }

            stk.push(node);
        }

        void getShortestPath(int src, vector<int> &dist, stack<int> &stk){
            dist[src] = 0;
            while(!stk.empty()){
                int topVal = stk.top();
                stk.pop();

                if(dist[topVal] != INT_MAX){
                    for(auto i: adjList[topVal]){
                        if(dist[topVal] + i.second < dist[i.first]){
                            dist[i.first] = dist[topVal] + i.second;
                        }
                    }
                }
            }
        }

        void printAdj(){
            for(auto i : adjList){
                cout << i.first << " -> ";
                for(auto j: i.second){
                    cout << "{" << j.first << ", " << j.second << "} ";             
                }
                cout << endl;
            }
        }

        void printShortestPath(vector<int> dist){
            cout << endl << "Ans is : ";
            for(int i=0; i<dist.size(); i++){
                cout << dist[i] << ", ";
            }
            cout << endl << endl;
        }

        
};

int main(){
    Graph g;
    g.addAdj(0, 1, 5);
    g.addAdj(0, 2, 3);
    g.addAdj(1, 2, 2);
    g.addAdj(1, 3, 6);
    g.addAdj(2, 3, 7);
    g.addAdj(2, 4, 4);
    g.addAdj(2, 5, 2);
    g.addAdj(3, 4, -1);
    g.addAdj(4, 5, -2);

    g.printAdj();

    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> stk;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, stk);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    } 
    g.getShortestPath(src, dist, stk);
    g.printShortestPath(dist);

    return 0;
}
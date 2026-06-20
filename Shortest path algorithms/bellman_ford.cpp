#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodes;
    vector<vector<int>> edges;

public:
    Graph(int n){
        nodes = n;
    }
    void edge(int u, int v, int w, int type){
        edges.push_back({u, v, w});
        if(type==2) edges.push_back({v, u, w});
    }
    vector<int> bellmanFord(int src){
        vector<int> dist(nodes+1, INT_MAX);
        dist[src] = 0;
        for(int i=1;i<nodes;i++){
            for(auto e : edges) {
                int u=e[0];
                int v=e[1];
                int w=e[2];
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]) {
                cout<<"Negative weight cycle detected!\n";
                return {};
            }
        }
        return dist;
    }
};

int main(){
    int nodes, edges;
    cout<<"Enter number of nodes:\n";
    cin>>nodes;
    Graph g(nodes);
    cout<<"Enter 1 for directed graph or 2 for undirected graph\n";
    int type;
    cin>>type;
    cout<<"Enter number of edges:\n";
    cin>>edges;
    cout<<"Enter the nodes for each edge along with the weight:\n";
    for(int i=0;i<edges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.edge(u, v, w, type);
    }
    int source;
    cout<<"Enter source node:\n";
    cin>>source;
    vector<int> dist = g.bellmanFord(source);
    if(dist.empty()) return 0;
    cout<<"\nShortest distances:\n";
    for(int i=1;i<=nodes;i++) {
        cout<<source<<" -> "<<i<<" = ";
        if(dist[i] == INT_MAX)
            cout<<"INFINITY";
        else
            cout<<dist[i];
        cout<<"\n";
    }
    return 0;
}
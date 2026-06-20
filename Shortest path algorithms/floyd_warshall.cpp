#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
    int nodes;
    const int INF = 1e9;
    vector<vector<int>> dist;

public:
    Graph(int n){
        nodes = n;
        dist.assign(nodes + 1, vector<int>(nodes + 1, INF));
        for(int i = 1; i <= nodes; i++){
            dist[i][i] = 0;
        }
    }
    void edge(int u, int v, int w, int type){
        dist[u][v] = min(dist[u][v], w);
        if(type == 2) {
            dist[v][u] = min(dist[v][u], w);
        }
    }
    bool floydWarshall(){
        for(int k = 1; k <= nodes; k++){
            for(int i = 1; i <= nodes; i++){
                for(int j = 1; j <= nodes; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        for(int i = 1; i <= nodes; i++){
            if(dist[i][i]<0){
                return false;
            }
        }
        return true;
    }

    void printDistances(){
        cout<<"\nAll-Pairs Shortest Paths:\n\n";
        for(int i = 1; i <= nodes; i++){
            for(int j = 1; j <= nodes; j++){
                cout<<i<<" --> "<<j<<" = ";
                if(dist[i][j] == INF) cout<<"INFINITY";
                else cout<<dist[i][j];
                cout<<"\n";
            }
        }
    }
};

int main(){
    int nodes, edges;
    cout<<"Enter number of nodes:\n";
    cin>>nodes;
    Graph g(nodes);
    cout<<"Enter 1 for directed graph or 2 for undirected graph:\n";
    int type;
    cin>>type;
    cout<<"Enter number of edges:\n";
    cin>>edges;
    cout<<"Enter the nodes for each edge and the weight:\n";
    for(int i = 0; i < edges; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.edge(u, v, w, type);
    }
    bool valid = g.floydWarshall();
    if(!valid){
        cout<<"\nNegative weight cycle detected!\n";
        return 0;
    }
    g.printDistances();
    return 0;
}
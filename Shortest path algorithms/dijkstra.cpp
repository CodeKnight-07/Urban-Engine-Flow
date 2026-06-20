#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodes;
    vector<vector<pair<int,int>>> adj;
public:
    Graph(int n){
        nodes = n;
        adj.resize(n+1);
    }
    void edge(int u, int v, int w, int type){
        adj[u].push_back({v, w});
        if(type==2) adj[v].push_back({u, w});
    }
    vector<int> dijkstra(int src){
        vector<int> dist(nodes + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(d>dist[u]) continue;
            for(const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
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
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.edge(u, v, w, type);
    }
    int source;
    cout<<"Enter source node:\n";
    cin>>source;
    vector<int> dist = g.dijkstra(source);
    cout<<"\nShortest distances:\n";
    for(int i = 1; i <= nodes; i++) {
        cout<<source<<" -> "<<i<<" = ";
        if(dist[i]==INT_MAX)
            cout<<"INFINITY";
        else
            cout<<dist[i];
        cout<<"\n";
    }
    return 0;
}

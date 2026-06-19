#include <bits/stdc++.h>
using namespace std;
class Graph {
private:
    int nodes;
    vector<vector<int>> adj;

public:
    Graph(int n){
        nodes = n;
        adj.resize(n+1);
    }

    void edge(int u, int v){
        adj[u].push_back(v);
    }

    vector<int> bfs(int start){
        vector<int> visited(nodes + 1, 0);
        vector<int> order;
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        return order;
    }
};

int main(){
    cout<<"Enter the number of nodes:\n";
    int nodes;
    cin>>nodes;
    Graph g(nodes);
    cout<<"Enter the number of edges:\n";
    int edges;
    cin>>edges;
    cout<<"Enter edges:\n";
    for (int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;
        g.edge(u, v);

    }

    cout<<"Enter starting node:\n";
    int start;
    cin>>start;
    vector<int> order = g.bfs(start);
    cout<<"Nodes visited in the following order:\n";

    for (size_t i=0;i<order.size();i++) {
        cout<<order[i];
        if (i+1<order.size())
            cout<<" --> ";
    }
    cout<<"\n";
    return 0;
}
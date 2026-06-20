#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int nodes;
    vector<vector<int>> adj;
    void dfsHelper(int node, vector<int>& visited, vector<int>& order) {
        visited[node] = 1;
        order.push_back(node);
        for (int v : adj[node]) {
            if (!visited[v]) {
                dfsHelper(v, visited, order);
            }
        }
    }
public:
    Graph(int n) {
        nodes = n;
        adj.resize(n + 1);
    }
    void edge(int u, int v) {
        adj[u].push_back(v);
    }
    vector<int> dfs(int start) {
        vector<int> visited(nodes + 1, 0);
        vector<int> order;
        dfsHelper(start, visited, order);
        return order;
    }
};

int main() {
    cout<<"Enter the number of nodes:\n";
    int nodes;
    cin>>nodes;
    Graph g(nodes);
    cout<<"Enter the number of edges:\n";
    int edges;
    cin>>edges;
    cout<<"Enter edges:\n";
    for (int i=0;i<edges;i++) {
        int u, v;
        cin>>u>>v;
        g.edge(u,v);
    }
    cout<<"Enter starting node:\n";
    int start;
    cin>>start;
    vector<int> order = g.dfs(start);
    cout << "Nodes visited in the following order:\n";
    for (size_t i = 0; i<order.size(); i++) {
        cout<<order[i];
        if (i+1<order.size())
            cout<<" --> ";
    }
    cout<<"\n";
    return 0;
}
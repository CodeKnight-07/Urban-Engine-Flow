#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodes;
    vector<vector<int>> capacity;
    vector<vector<int>> remainingCapacity;
    vector<vector<int>> adj;
    int dfs(int s, vector<int> &visited, int sink, int curFlow, int v){
        if(s == sink){
            return curFlow;
        }
        visited[s] = v;
        for(int u:adj[s]){
            if(remainingCapacity[s][u]>0 && visited[u] != v){
                int bottleNeck = dfs(u,visited, sink, min(curFlow, remainingCapacity[s][u]), v);
                if(bottleNeck != 0){
                    remainingCapacity[s][u] -= bottleNeck;
                    remainingCapacity[u][s] += bottleNeck;
                    return bottleNeck;
                }
            }
        }
        return 0;
    }

public:
    vector<vector<int>> flow;
    Graph(int n){
        nodes = n;
        capacity.assign(nodes + 1, vector<int>(nodes + 1, 0));
        remainingCapacity.assign(nodes + 1, vector<int>(nodes + 1, 0));
        flow.assign(nodes + 1, vector<int>(nodes + 1, 0));
        adj.assign(nodes + 1, vector<int>());
    }
    void edge(int u, int v, int cap){
        if(capacity[u][v] == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        capacity[u][v] += cap;
        remainingCapacity[u][v] += cap;
    }
    int fordFulkerson(int source, int sink){
        int maxFlow = 0;
        vector<int> visited(nodes + 1, 0);
        int curFlow = INT_MAX;
        int v = 1;
        int bottleNeck = dfs(source, visited, sink, curFlow, v);
        while(bottleNeck != 0){
            v++;
            maxFlow += bottleNeck;
            bottleNeck = dfs(source, visited, sink, curFlow, v);
            
        }
        return maxFlow;
    }
    void calculateFlow(const vector<vector<int>> &e){
        for(auto i : e){
            flow[i[0]][i[1]] = capacity[i[0]][i[1]]-remainingCapacity[i[0]][i[1]];
        }
    }
};

int main(){
    int nodes, edges;
    cout<<"Enter number of nodes:\n";
    cin>>nodes;
    Graph g(nodes);
    cout<<"Enter number of edges:\n";
    cin>>edges;
    cout<<"Enter each edge along with its capacity:\n";
    vector<vector<int>> edge;
    for(int i = 0; i < edges; i++){
        int u, v, cap;
        cin>>u>>v>>cap;
        g.edge(u, v, cap);
        vector<int> e  = {u, v, cap};
        edge.emplace_back(e);
    }
    int source, sink;
    cout<<"Enter source node:\n";
    cin>>source;
    cout<<"Enter sink node:\n";
    cin>>sink;
    int maxFlow = g.fordFulkerson(source, sink);
    g.calculateFlow(edge);
    cout<<"\nMaximum Flow = "<<maxFlow<<"\n";
    cout<<"\nEdges' flow and capacities:\n";
    for(auto i : edge){
        cout<<i[0]<<" --> "<<i[1]<<", Flow = "<<g.flow[i[0]][i[1]]<<",  Capacity = "<<i[2]<<"\n";
    }
    return 0;
}
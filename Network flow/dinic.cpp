#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodes;
    vector<vector<int>> capacity;
    vector<vector<int>> remainingCapacity;
    vector<vector<int>> adj;
    bool bfs(int s, int sink, vector<int> &level){
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:adj[u]){
                if(remainingCapacity[u][v]>0 && level[v] == -1){
                    q.push(v);
                    level[v] = level[u] + 1;
                }
                
            }
        }
        return level[sink] != -1;
    }

    int dfs(int s, int sink, int curFlow, const vector<int> &level, vector<int> &ptr){
        if(s == sink){
            return curFlow;
        }
        for(; ptr[s]<adj[s].size();ptr[s]++){
            int u = adj[s][ptr[s]];
            if(remainingCapacity[s][u]>0 && level[u] == level[s] + 1){
                int bottleNeck = dfs(u, sink, min(curFlow, remainingCapacity[s][u]), level, ptr);
                if(bottleNeck > 0){
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
    int dinic(int source, int sink){
        int maxFlow = 0;
        vector<int> level(nodes + 1, -1);
        while(bfs(source, sink, level)){
            vector<int> ptr(nodes + 1, 0);
            int bottleNeck = dfs(source, sink, INT_MAX, level, ptr);
            while(bottleNeck != 0){
                maxFlow += bottleNeck;
                bottleNeck = dfs(source, sink, INT_MAX, level, ptr);
                
            }
            fill(level.begin(), level.end(), -1);
        }
        
        return maxFlow;
    }
    void calculateFlow(const vector<vector<int>> &e){
        for(const auto &i : e){
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
    int maxFlow = g.dinic(source, sink);
    g.calculateFlow(edge);
    cout<<"\nMaximum Flow = "<<maxFlow<<"\n";
    cout<<"\nEdges' flow and capacities:\n";
    for(auto i : edge){
        cout<<i[0]<<" --> "<<i[1]<<", Flow = "<<g.flow[i[0]][i[1]]<<",  Capacity = "<<i[2]<<"\n";
    }
    return 0;
}
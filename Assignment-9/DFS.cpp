#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool undirected = false) {
        adj[u].push_back(v);
        if (undirected) adj[v].push_back(u);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void dfsHelper(int node, vector<int> &visited) {
        visited[node] = 1;
        cout << node << " ";

        for (int i = 0; i < adj[node].size(); i++) {
            int nxt = adj[node][i];
            if (!visited[nxt]) dfsHelper(nxt, visited);
        }
    }

    void DFS(int start) {
        vector<int> visited(V, 0);
        dfsHelper(start, visited);
        cout << "\n";
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);  
    }

    cout << "DFS from 0: ";
    g.DFS(0);

    return 0;
}

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

    void BFS(int start) {
        vector<int> visited(V, 0);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < adj[node].size(); i++) {
                int nxt = adj[node][i];
                if (!visited[nxt]) {
                    visited[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
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

    cout << "BFS from 0: ";
    g.BFS(0);

    return 0;
}

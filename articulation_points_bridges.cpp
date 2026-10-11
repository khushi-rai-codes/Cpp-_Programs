#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Graph {
private:
    int vertices;
    int timer = 0;

    vector<vector<pair<int, int>>> adj;
    vector<int> discovery, low, parent;
    vector<bool> articulation;
    vector<pair<int, int>> bridges;

    void dfs(int u) {
        discovery[u] = low[u] = ++timer;
        int children = 0;

        for (auto [v, edgeId] : adj[u]) {
            if (edgeId == parent[u])
                continue;

            if (discovery[v] == 0) {
                parent[v] = edgeId;
                children++;

                dfs(v);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1)
                    articulation[u] = true;

                if (parent[u] != -1 &&
                    low[v] >= discovery[u])
                    articulation[u] = true;

                if (low[v] > discovery[u])
                    bridges.push_back({min(u, v), max(u, v)});
            } else {
                low[u] = min(low[u], discovery[v]);
            }
        }
    }

public:
    explicit Graph(int n)
        : vertices(n),
          adj(n),
          discovery(n, 0),
          low(n, 0),
          parent(n, -1),
          articulation(n, false) {}

    void addEdge(int u, int v, int edgeId) {
        adj[u].push_back({v, edgeId});
        adj[v].push_back({u, edgeId});
    }

    void analyze() {
        for (int i = 0; i < vertices; i++) {
            if (discovery[i] == 0)
                dfs(i);
        }

        cout << "\nArticulation points:\n";
        bool found = false;

        for (int i = 0; i < vertices; i++) {
            if (articulation[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << "\n\nBridges:\n";

        if (bridges.empty()) {
            cout << "None\n";
        } else {
            sort(bridges.begin(), bridges.end());

            for (auto [u, v] : bridges)
                cout << u << " -- " << v << '\n';
        }
    }
};

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";

    if (!(cin >> n >> m) || n <= 0 || m < 0) {
        cout << "Invalid graph dimensions.\n";
        return 1;
    }

    Graph graph(n);

    cout << "Enter each undirected edge (u v), using vertices 0 to "
         << n - 1 << ":\n";

    for (int i = 0; i < m; i++) {
        int u, v;

        if (!(cin >> u >> v) ||
            u < 0 || u >= n ||
            v < 0 || v >= n ||
            u == v) {
            cout << "Invalid edge.\n";
            return 1;
        }

        graph.addEdge(u, v, i);
    }

    graph.analyze();

    return 0;
}

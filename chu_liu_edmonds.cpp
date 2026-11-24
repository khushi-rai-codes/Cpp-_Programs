#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
    int from, to;
    long long weight;
};

long long directedMST(
    int n,
    int root,
    vector<Edge> edges
) {
    const long long INF =
        numeric_limits<long long>::max() / 4;

    long long answer = 0;

    while (true) {
        vector<long long> in(n, INF);
        vector<int> pre(n, -1);

        // Find minimum incoming edge for each vertex.
        for (const Edge& e : edges) {
            if (e.from != e.to && e.weight < in[e.to]) {
                in[e.to] = e.weight;
                pre[e.to] = e.from;
            }
        }

        in[root] = 0;

        for (int i = 0; i < n; i++) {
            if (in[i] == INF)
                return -1;
        }

        for (int i = 0; i < n; i++)
            answer += in[i];

        // Detect cycles.
        int cycleCount = 0;

        vector<int> id(n, -1);
        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++) {
            int v = i;

            while (visited[v] != i &&
                   id[v] == -1 &&
                   v != root) {

                visited[v] = i;
                v = pre[v];
            }

            if (v != root && id[v] == -1) {
                for (int u = pre[v]; u != v; u = pre[u])
                    id[u] = cycleCount;

                id[v] = cycleCount++;
            }
        }

        // No cycles: answer is complete.
        if (cycleCount == 0)
            return answer;

        // Assign new IDs to vertices outside cycles.
        for (int i = 0; i < n; i++) {
            if (id[i] == -1)
                id[i] = cycleCount++;
        }

        vector<Edge> newEdges;

        for (const Edge& e : edges) {
            int u = id[e.from];
            int v = id[e.to];

            if (u != v) {
                newEdges.push_back({
                    u,
                    v,
                    e.weight - in[e.to]
                });
            }
        }

        root = id[root];
        n = cycleCount;
        edges = move(newEdges);
    }
}

int main() {
    int vertices = 4;
    int root = 0;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 10},
        {1, 2, 1},
        {2, 1, 1},
        {1, 3, 5},
        {2, 3, 4},
        {3, 0, 8}
    };

    long long result =
        directedMST(vertices, root, edges);

    if (result == -1) {
        cout << "No spanning arborescence exists.\n";
    } else {
        cout << "Root Vertex: " << root << endl;
        cout << "Minimum Arborescence Cost: "
             << result << endl;
    }

    return 0;
}

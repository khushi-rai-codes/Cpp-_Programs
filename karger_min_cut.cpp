#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
using namespace std;

class KargerMinCut {
    int n;
    vector<pair<int, int>> edges;
    mt19937 rng;

    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);

            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];

            return true;
        }
    };

public:
    KargerMinCut(
        int vertices,
        vector<pair<int, int>> graphEdges
    ) : n(vertices),
        edges(move(graphEdges)),
        rng(random_device{}()) {}

    int singleTrial() {
        DSU dsu(n);
        int components = n;

        while (components > 2) {
            vector<pair<int, int>> validEdges;

            for (auto [u, v] : edges) {
                if (dsu.find(u) != dsu.find(v))
                    validEdges.push_back({u, v});
            }

            if (validEdges.empty())
                return 0;

            uniform_int_distribution<int> distribution(
                0, static_cast<int>(validEdges.size()) - 1
            );

            auto [u, v] = validEdges[distribution(rng)];

            if (dsu.unite(u, v))
                components--;
        }

        int cut = 0;

        for (auto [u, v] : edges) {
            if (dsu.find(u) != dsu.find(v))
                cut++;
        }

        return cut;
    }

    int findMinimumCut(int trials) {
        int answer = static_cast<int>(edges.size());

        for (int i = 0; i < trials; i++) {
            answer = min(answer, singleTrial());
        }

        return answer;
    }
};

int main() {
    int vertices = 6;

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2},
        {1, 2}, {1, 3},
        {2, 3}, {2, 4},
        {3, 4}, {3, 5},
        {4, 5}
    };

    KargerMinCut graph(vertices, edges);

    int trials = 1000;

    cout << "Number of Vertices: " << vertices << endl;
    cout << "Number of Edges: " << edges.size() << endl;

    cout << "Minimum Cut Estimate: "
         << graph.findMinimumCut(trials) << endl;

    return 0;
}

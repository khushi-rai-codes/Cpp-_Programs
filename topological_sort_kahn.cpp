#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(
    int vertices,
    const vector<vector<int>>& graph
) {
    vector<int> indegree(vertices, 0);

    for (int u = 0; u < vertices; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        order.push_back(current);

        for (int next : graph[current]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if ((int)order.size() != vertices) {
        return {};
    }

    return order;
}

int main() {
    int vertices = 6;

    vector<vector<int>> graph(vertices);

    graph[5].push_back(2);
    graph[5].push_back(0);

    graph[4].push_back(0);
    graph[4].push_back(1);

    graph[2].push_back(3);

    graph[3].push_back(1);

    vector<int> result =
        topologicalSort(vertices, graph);

    if (result.empty()) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Topological ordering:\n";

        for (int vertex : result) {
            cout << vertex << " ";
        }

        cout << '\n';
    }

    return 0;
}

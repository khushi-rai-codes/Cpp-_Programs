#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> Pair;

void dijkstra(
    int vertices,
    vector<vector<Pair>>& graph,
    int source
) {
    const int INF = numeric_limits<int>::max();

    vector<int> distance(vertices, INF);

    priority_queue<
        Pair,
        vector<Pair>,
        greater<Pair>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentVertex]) {
            continue;
        }

        for (auto edge : graph[currentVertex]) {
            int nextVertex = edge.first;
            int weight = edge.second;

            if (distance[currentVertex] + weight <
                distance[nextVertex]) {

                distance[nextVertex] =
                    distance[currentVertex] + weight;

                pq.push({
                    distance[nextVertex],
                    nextVertex
                });
            }
        }
    }

    cout << "Shortest distances from vertex "
         << source << ":\n";

    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";

        if (distance[i] == INF) {
            cout << "INF";
        } else {
            cout << distance[i];
        }

        cout << '\n';
    }
}

int main() {
    int vertices = 6;

    vector<vector<Pair>> graph(vertices);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});

    graph[1].push_back({2, 5});
    graph[1].push_back({3, 10});

    graph[2].push_back({4, 3});

    graph[4].push_back({3, 4});
    graph[3].push_back({5, 11});

    dijkstra(vertices, graph, 0);

    return 0;
}

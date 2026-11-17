#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TwoSAT {
    int n;

    vector<vector<int>> graph, reverseGraph;
    vector<bool> visited;
    vector<int> order, component;

    int node(int literal) {
        int variable = abs(literal) - 1;

        return 2 * variable + (literal < 0);
    }

    void dfs1(int u) {
        visited[u] = true;

        for (int v : graph[u]) {
            if (!visited[v])
                dfs1(v);
        }

        order.push_back(u);
    }

    void dfs2(int u, int id) {
        component[u] = id;

        for (int v : reverseGraph[u]) {
            if (component[v] == -1)
                dfs2(v, id);
        }
    }

public:
    TwoSAT(int variables) : n(variables) {
        graph.resize(2 * n);
        reverseGraph.resize(2 * n);
    }

    void addClause(int a, int b) {
        int x = node(a);
        int y = node(b);

        // NOT a implies b.
        graph[x ^ 1].push_back(y);
        reverseGraph[y].push_back(x ^ 1);

        // NOT b implies a.
        graph[y ^ 1].push_back(x);
        reverseGraph[x].push_back(y ^ 1);
    }

    bool solve(vector<bool>& assignment) {
        int total = 2 * n;

        visited.assign(total, false);
        component.assign(total, -1);

        order.clear();

        for (int i = 0; i < total; i++) {
            if (!visited[i])
                dfs1(i);
        }

        reverse(order.begin(), order.end());

        int id = 0;

        for (int u : order) {
            if (component[u] == -1)
                dfs2(u, id++);
        }

        assignment.resize(n);

        for (int i = 0; i < n; i++) {
            int falseNode = 2 * i;
            int trueNode = 2 * i + 1;

            if (component[falseNode] ==
                component[trueNode]) {
                return false;
            }

            assignment[i] =
                component[trueNode] > component[falseNode];
        }

        return true;
    }
};

int main() {
    int variables, clauses;

    cout << "Enter number of variables and clauses: ";
    cin >> variables >> clauses;

    if (variables <= 0 || clauses < 0)
        return 1;

    TwoSAT solver(variables);

    cout << "Enter each clause as two signed literals.\n";
    cout << "Example: 1 -2 represents (x1 OR NOT x2).\n";

    for (int i = 0; i < clauses; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 0 || b == 0 ||
            abs(a) > variables || abs(b) > variables) {
            cout << "Invalid literal.\n";
            return 1;
        }

        solver.addClause(a, b);
    }

    vector<bool> assignment;

    if (solver.solve(assignment)) {
        cout << "\nSATISFIABLE\n";
        cout << "Valid assignment:\n";

        for (int i = 0; i < variables; i++) {
            cout << "x" << i + 1 << " = "
                 << (assignment[i] ? "TRUE" : "FALSE")
                 << '\n';
        }
    } else {
        cout << "\nUNSATISFIABLE\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

struct Operation {
    char type;
    int u, v;
};

struct Change {
    int child;
    int parent;
    int oldSize;
};

class RollbackDSU {
private:
    vector<int> parent, sz;
    vector<Change> history;

public:
    explicit RollbackDSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        while (parent[x] != x)
            x = parent[x];

        return x;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            history.push_back({-1, -1, -1});
            return;
        }

        if (sz[a] < sz[b])
            swap(a, b);

        history.push_back({b, a, sz[a]});

        parent[b] = a;
        sz[a] += sz[b];
    }

    int snapshot() const {
        return (int)history.size();
    }

    void rollback(int snapshotSize) {
        while ((int)history.size() > snapshotSize) {
            Change c = history.back();
            history.pop_back();

            if (c.child == -1)
                continue;

            parent[c.child] = c.child;
            sz[c.parent] = c.oldSize;
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

class DynamicConnectivity {
private:
    int n, q;
    vector<Operation> operations;
    vector<vector<pair<int, int>>> tree;
    RollbackDSU dsu;

    void addInterval(int node, int start, int end,
                     int L, int R, pair<int, int> edge) {
        if (R <= start || end <= L)
            return;

        if (L <= start && end <= R) {
            tree[node].push_back(edge);
            return;
        }

        int mid = start + (end - start) / 2;

        addInterval(node * 2, start, mid, L, R, edge);
        addInterval(node * 2 + 1, mid, end, L, R, edge);
    }

    void solve(int node, int start, int end) {
        int checkpoint = dsu.snapshot();

        for (auto [u, v] : tree[node])
            dsu.unite(u, v);

        if (end - start == 1) {
            const Operation& op = operations[start];

            if (op.type == '?') {
                cout << (dsu.connected(op.u, op.v)
                         ? "CONNECTED\n"
                         : "DISCONNECTED\n");
            }
        } else {
            int mid = start + (end - start) / 2;

            solve(node * 2, start, mid);
            solve(node * 2 + 1, mid, end);
        }

        dsu.rollback(checkpoint);
    }

public:
    DynamicConnectivity(int vertices, int queries)
        : n(vertices), q(queries), dsu(vertices) {
        operations.resize(q);
        tree.resize(4 * q + 4);
    }

    void readOperations() {
        map<pair<int, int>, int> active;

        for (int i = 0; i < q; i++) {
            char type;
            int u, v;

            cin >> type >> u >> v;

            if (u < 0 || u >= n || v < 0 || v >= n ||
                (type != '+' && type != '-' && type != '?')) {
                throw invalid_argument("Invalid operation.");
            }

            if (u > v)
                swap(u, v);

            operations[i] = {type, u, v};

            pair<int, int> edge = {u, v};

            if (type == '+') {
                if (active.count(edge))
                    throw invalid_argument("Edge already active.");

                active[edge] = i;
            } else if (type == '-') {
                if (!active.count(edge))
                    throw invalid_argument("Edge is not active.");

                addInterval(1, 0, q, active[edge], i, edge);
                active.erase(edge);
            }
        }

        for (auto [edge, start] : active)
            addInterval(1, 0, q, start, q, edge);
    }

    void run() {
        if (q > 0)
            solve(1, 0, q);
    }
};

int main() {
    int n, q;

    cout << "Enter vertices and operations: ";

    if (!(cin >> n >> q) || n <= 0 || q < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    try {
        DynamicConnectivity graph(n, q);

        cout << "Operations:\n";
        cout << "+ u v : Add edge\n";
        cout << "- u v : Remove edge\n";
        cout << "? u v : Check connectivity\n";

        graph.readOperations();

        cout << "\nConnectivity results:\n";
        graph.run();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}

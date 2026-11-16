#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree;

    void build(int node, int l, int r,
               const vector<long long>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int node, int l, int r,
                int pos, long long value) {
        if (l == r) {
            tree[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, value);
        else
            update(node * 2 + 1, mid + 1, r, pos, value);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int l, int r,
                    int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) +
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(const vector<long long>& a) {
        n = (int)a.size();
        tree.assign(4 * n + 1, 0);

        if (n > 0)
            build(1, 0, n - 1, a);
    }

    void update(int pos, long long value) {
        update(1, 0, n - 1, pos, value);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class HeavyLightDecomposition {
    int n, timer = 0;

    vector<vector<int>> adj;
    vector<int> parent, depth, subtree;
    vector<int> heavy, head, position;
    vector<long long> values;

    SegmentTree* seg = nullptr;

    int dfs(int u, int p) {
        parent[u] = p;
        subtree[u] = 1;

        int largest = 0;

        for (int v : adj[u]) {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;

            int size = dfs(v, u);

            subtree[u] += size;

            if (size > largest) {
                largest = size;
                heavy[u] = v;
            }
        }

        return subtree[u];
    }

    void decompose(int u, int h, vector<long long>& base) {
        head[u] = h;
        position[u] = timer;

        base[timer++] = values[u];

        if (heavy[u] != -1)
            decompose(heavy[u], h, base);

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u])
                decompose(v, v, base);
        }
    }

public:
    HeavyLightDecomposition(int n)
        : n(n),
          adj(n + 1),
          parent(n + 1),
          depth(n + 1),
          subtree(n + 1),
          heavy(n + 1, -1),
          head(n + 1),
          position(n + 1),
          values(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void setValue(int u, long long value) {
        values[u] = value;
    }

    void build(int root = 1) {
        dfs(root, 0);

        vector<long long> base(n);
        decompose(root, root, base);

        seg = new SegmentTree(base);
    }

    void update(int u, long long value) {
        values[u] = value;
        seg->update(position[u], value);
    }

    long long pathQuery(int u, int v) {
        long long result = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            result += seg->query(
                position[head[u]], position[u]
            );

            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        result += seg->query(position[u], position[v]);

        return result;
    }

    ~HeavyLightDecomposition() {
        delete seg;
    }
};

int main() {
    int n, q;

    cout << "Enter number of nodes and queries: ";
    cin >> n >> q;

    if (n <= 0 || q < 0)
        return 1;

    HeavyLightDecomposition hld(n);

    cout << "Enter node values:\n";

    for (int i = 1; i <= n; i++) {
        long long value;
        cin >> value;
        hld.setValue(i, value);
    }

    cout << "Enter " << n - 1 << " edges:\n";

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        hld.addEdge(u, v);
    }

    hld.build();

    cout << "\nQueries:\n";
    cout << "1 u value  -> Update node value\n";
    cout << "2 u v      -> Path sum query\n";

    while (q--) {
        int type, u;
        cin >> type >> u;

        if (type == 1) {
            long long value;
            cin >> value;

            hld.update(u, value);
        } else if (type == 2) {
            int v;
            cin >> v;

            cout << "Path sum: "
                 << hld.pathQuery(u, v) << '\n';
        } else {
            cout << "Invalid query type.\n";
            return 1;
        }
    }

    return 0;
}

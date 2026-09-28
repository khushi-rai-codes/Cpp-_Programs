#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            cout << "Elements are already connected.\n";
            return;
        }

        if (rankValue[rootA] < rankValue[rootB]) {
            parent[rootA] = rootB;
        } else if (rankValue[rootA] > rankValue[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }

        cout << "Sets merged successfully.\n";
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements.\n";
        return 0;
    }

    DSU dsu(n);

    int choice;

    do {
        cout << "\n===== DISJOINT SET UNION =====\n";
        cout << "1. Union\n";
        cout << "2. Check Connection\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int a, b;

            cout << "Enter two elements: ";
            cin >> a >> b;

            if (a < 0 || a >= n || b < 0 || b >= n) {
                cout << "Invalid elements.\n";
            } else {
                dsu.unite(a, b);
            }
        }
        else if (choice == 2) {
            int a, b;

            cout << "Enter two elements: ";
            cin >> a >> b;

            if (a < 0 || a >= n || b < 0 || b >= n) {
                cout << "Invalid elements.\n";
            } else if (dsu.connected(a, b)) {
                cout << "Elements are connected.\n";
            } else {
                cout << "Elements are not connected.\n";
            }
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}

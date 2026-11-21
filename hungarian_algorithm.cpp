#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> hungarian(const vector<vector<int>>& cost) {
    int n = cost.size();

    vector<int> u(n + 1), v(n + 1);
    vector<int> p(n + 1), way(n + 1);

    for (int i = 1; i <= n; i++) {
        p[0] = i;

        int j0 = 0;
        vector<int> minv(n + 1, INT_MAX);
        vector<bool> used(n + 1, false);

        do {
            used[j0] = true;

            int i0 = p[j0];
            int delta = INT_MAX;
            int j1 = 0;

            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    int current =
                        cost[i0 - 1][j - 1] - u[i0] - v[j];

                    if (current < minv[j]) {
                        minv[j] = current;
                        way[j] = j0;
                    }

                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= n; j++) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }

            j0 = j1;

        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    vector<int> assignment(n);

    for (int j = 1; j <= n; j++)
        assignment[p[j] - 1] = j - 1;

    return assignment;
}

int main() {
    vector<vector<int>> cost = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    vector<int> result = hungarian(cost);

    int totalCost = 0;

    cout << "Optimal Assignment:\n";

    for (int i = 0; i < result.size(); i++) {
        cout << "Worker " << i + 1
             << " -> Job " << result[i] + 1
             << " | Cost: " << cost[i][result[i]]
             << endl;

        totalCost += cost[i][result[i]];
    }

    cout << "\nMinimum Total Cost: "
         << totalCost << endl;

    return 0;
}

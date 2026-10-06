#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Node {
    int row;
    int col;
    int g;
    int h;

    int f() const {
        return g + h;
    }

    bool operator>(const Node& other) const {
        return f() > other.f();
    }
};

int heuristic(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

bool isValid(
    int row,
    int col,
    const vector<vector<int>>& grid
) {
    return row >= 0 &&
           row < (int)grid.size() &&
           col >= 0 &&
           col < (int)grid[0].size() &&
           grid[row][col] == 0;
}

void printPath(
    const vector<vector<pair<int, int>>>& parent,
    int startRow,
    int startCol,
    int endRow,
    int endCol
) {
    vector<pair<int, int>> path;

    int row = endRow;
    int col = endCol;

    while (!(row == startRow && col == startCol)) {
        path.push_back({row, col});

        pair<int, int> previous = parent[row][col];

        if (previous.first == -1) {
            cout << "No path found.\n";
            return;
        }

        row = previous.first;
        col = previous.second;
    }

    path.push_back({startRow, startCol});

    reverse(path.begin(), path.end());

    cout << "Path:\n";

    for (auto cell : path) {
        cout << "(" << cell.first
             << ", " << cell.second << ") ";

    }

    cout << "\n";
}

void aStar(
    const vector<vector<int>>& grid,
    pair<int, int> start,
    pair<int, int> goal
) {
    int rows = grid.size();
    int cols = grid[0].size();

    const int INF = numeric_limits<int>::max();

    vector<vector<int>> distance(
        rows,
        vector<int>(cols, INF)
    );

    vector<vector<pair<int, int>>> parent(
        rows,
        vector<pair<int, int>>(cols, {-1, -1})
    );

    priority_queue<
        Node,
        vector<Node>,
        greater<Node>
    > openSet;

    distance[start.first][start.second] = 0;

    openSet.push({
        start.first,
        start.second,
        0,
        heuristic(
            start.first,
            start.second,
            goal.first,
            goal.second
        )
    });

    int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.row == goal.first &&
            current.col == goal.second) {

            printPath(
                parent,
                start.first,
                start.second,
                goal.first,
                goal.second
            );

            cout << "Path cost: "
                 << distance[goal.first][goal.second]
                 << "\n";

            return;
        }

        for (auto& direction : directions) {
            int newRow = current.row + direction[0];
            int newCol = current.col + direction[1];

            if (!isValid(newRow, newCol, grid)) {
                continue;
            }

            int newCost = distance[current.row][current.col] + 1;

            if (newCost < distance[newRow][newCol]) {
                distance[newRow][newCol] = newCost;

                parent[newRow][newCol] = {
                    current.row,
                    current.col
                };

                int h = heuristic(
                    newRow,
                    newCol,
                    goal.first,
                    goal.second
                );

                openSet.push({
                    newRow,
                    newCol,
                    newCost,
                    h
                });
            }
        }
    }

    cout << "No path found.\n";
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {5, 5};

    aStar(grid, start, goal);

    return 0;
}

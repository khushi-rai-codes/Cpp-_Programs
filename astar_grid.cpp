#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

struct Node {
    int x, y;
    int g, f;

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int heuristic(int x, int y, int gx, int gy) {
    return abs(x - gx) + abs(y - gy);
}

bool valid(int x, int y, int rows, int cols,
           const vector<vector<int>>& grid) {
    return x >= 0 && x < rows &&
           y >= 0 && y < cols &&
           grid[x][y] == 0;
}

vector<pair<int, int>> findPath(
    const vector<vector<int>>& grid,
    pair<int, int> start,
    pair<int, int> goal
) {
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();

    vector<vector<int>> gScore(
        rows, vector<int>(cols, 1e9)
    );

    vector<vector<pair<int, int>>> parent(
        rows, vector<pair<int, int>>(cols, {-1, -1})
    );

    priority_queue<Node, vector<Node>, greater<Node>> open;

    int sx = start.first, sy = start.second;
    int gx = goal.first, gy = goal.second;

    gScore[sx][sy] = 0;

    open.push({
        sx, sy, 0,
        heuristic(sx, sy, gx, gy)
    });

    while (!open.empty()) {
        Node current = open.top();
        open.pop();

        int x = current.x;
        int y = current.y;

        if (current.g != gScore[x][y])
            continue;

        if (x == gx && y == gy) {
            vector<pair<int, int>> path;

            while (x != -1 && y != -1) {
                path.push_back({x, y});

                auto previous = parent[x][y];
                x = previous.first;
                y = previous.second;
            }

            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!valid(nx, ny, rows, cols, grid))
                continue;

            int newG = gScore[x][y] + 1;

            if (newG < gScore[nx][ny]) {
                gScore[nx][ny] = newG;
                parent[nx][ny] = {x, y};

                int newF = newG +
                    heuristic(nx, ny, gx, gy);

                open.push({nx, ny, newG, newF});
            }
        }
    }

    return {};
}

int main() {
    int rows, cols;

    cout << "Enter grid dimensions: ";

    if (!(cin >> rows >> cols) ||
        rows <= 0 || cols <= 0 ||
        rows > 1000 || cols > 1000) {
        cout << "Invalid dimensions.\n";
        return 1;
    }

    vector<vector<int>> grid(
        rows, vector<int>(cols)
    );

    cout << "Enter grid (0 = free, 1 = obstacle):\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> grid[i][j]) ||
                (grid[i][j] != 0 && grid[i][j] != 1)) {
                cout << "Invalid grid value.\n";
                return 1;
            }
        }
    }

    int sx, sy, gx, gy;

    cout << "Enter start coordinates: ";
    if (!(cin >> sx >> sy)) {
        cout << "Invalid coordinates.\n";
        return 1;
    }

    cout << "Enter goal coordinates: ";
    if (!(cin >> gx >> gy)) {
        cout << "Invalid coordinates.\n";
        return 1;
    }

    if (!valid(sx, sy, rows, cols, grid) ||
        !valid(gx, gy, rows, cols, grid)) {
        cout << "Start or goal is invalid.\n";
        return 1;
    }

    auto path = findPath(grid, {sx, sy}, {gx, gy});

    if (path.empty()) {
        cout << "No path found.\n";
        return 0;
    }

    cout << "\nShortest path:\n";

    for (auto [x, y] : path)
        cout << "(" << x << ", " << y << ") ";

    cout << "\nPath length: " << path.size() - 1 << '\n';

    return 0;
}

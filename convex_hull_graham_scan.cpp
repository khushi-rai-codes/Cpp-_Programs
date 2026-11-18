#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

long long cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

long long distanceSquared(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;

    return dx * dx + dy * dy;
}

Point pivot;

bool polarCompare(Point a, Point b) {
    long long c = cross(pivot, a, b);

    if (c != 0)
        return c > 0;

    return distanceSquared(pivot, a) <
           distanceSquared(pivot, b);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();

    if (n <= 1)
        return points;

    int lowest = 0;

    for (int i = 1; i < n; i++) {
        if (points[i].y < points[lowest].y ||
            (points[i].y == points[lowest].y &&
             points[i].x < points[lowest].x)) {
            lowest = i;
        }
    }

    swap(points[0], points[lowest]);

    pivot = points[0];

    sort(points.begin() + 1, points.end(), polarCompare);

    vector<Point> uniquePoints;

    for (const Point& p : points) {
        while (uniquePoints.size() >= 2 &&
               cross(uniquePoints[uniquePoints.size() - 2],
                     uniquePoints.back(), p) == 0) {
            // Retain the farthest point on each ray.
            if (distanceSquared(pivot, p) >
                distanceSquared(pivot, uniquePoints.back())) {
                uniquePoints.pop_back();
            } else {
                break;
            }
        }

        if (uniquePoints.empty() ||
            !(uniquePoints.back() == p)) {
            uniquePoints.push_back(p);
        }
    }

    if (uniquePoints.size() < 3)
        return uniquePoints;

    vector<Point> hull;

    for (const Point& p : uniquePoints) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size() - 2],
                     hull.back(), p) <= 0) {
            hull.pop_back();
        }

        hull.push_back(p);
    }

    return hull;
}

int main() {
    int n;

    cout << "Enter number of points: ";
    cin >> n;

    if (n <= 0)
        return 1;

    vector<Point> points(n);

    cout << "Enter coordinates (x y):\n";

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end(),
         [](const Point& a, const Point& b) {
             if (a.x != b.x)
                 return a.x < b.x;

             return a.y < b.y;
         });

    points.erase(
        unique(points.begin(), points.end()),
        points.end()
    );

    vector<Point> hull = convexHull(points);

    cout << "\nCONVEX HULL POINTS:\n";

    for (const Point& p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    cout << "\nNumber of hull vertices: "
         << hull.size() << '\n';

    return 0;
}

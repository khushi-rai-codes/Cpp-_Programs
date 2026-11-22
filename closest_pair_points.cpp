#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Point {
    double x, y;
};

struct Answer {
    Point first, second;
    double distance;
};

double distanceBetween(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

Answer bruteForce(const vector<Point>& points) {
    Answer best;
    best.distance = numeric_limits<double>::infinity();

    for (int i = 0; i < (int)points.size(); i++) {
        for (int j = i + 1; j < (int)points.size(); j++) {
            double d = distanceBetween(points[i], points[j]);

            if (d < best.distance) {
                best = {points[i], points[j], d};
            }
        }
    }

    return best;
}

Answer closestPair(vector<Point>& points,
                   vector<Point>& byY) {
    int n = points.size();

    if (n <= 3)
        return bruteForce(points);

    int mid = n / 2;
    double midX = points[mid].x;

    vector<Point> left(points.begin(),
                       points.begin() + mid);

    vector<Point> right(points.begin() + mid,
                        points.end());

    vector<Point> leftY, rightY;

    for (const Point& p : byY) {
        if (p.x < midX ||
            (p.x == midX &&
             leftY.size() < left.size())) {
            leftY.push_back(p);
        } else {
            rightY.push_back(p);
        }
    }

    Answer a = closestPair(left, leftY);
    Answer b = closestPair(right, rightY);

    Answer best = (a.distance < b.distance) ? a : b;

    vector<Point> strip;

    for (const Point& p : byY) {
        if (abs(p.x - midX) < best.distance)
            strip.push_back(p);
    }

    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1;
             j < (int)strip.size() &&
             strip[j].y - strip[i].y < best.distance;
             j++) {

            double d = distanceBetween(strip[i], strip[j]);

            if (d < best.distance) {
                best = {strip[i], strip[j], d};
            }
        }
    }

    return best;
}

int main() {
    vector<Point> points = {
        {2, 3}, {12, 30}, {40, 50},
        {5, 1}, {12, 10}, {3, 4},
        {8, 9}, {15, 16}
    };

    if (points.size() < 2) {
        cout << "At least two points are required.\n";
        return 0;
    }

    vector<Point> byY = points;

    sort(points.begin(), points.end(), compareX);
    sort(byY.begin(), byY.end(), compareY);

    Answer result = closestPair(points, byY);

    cout << "Closest Points:\n";

    cout << "(" << result.first.x << ", "
         << result.first.y << ")\n";

    cout << "(" << result.second.x << ", "
         << result.second.y << ")\n";

    cout << "Minimum Distance: "
         << result.distance << endl;

    return 0;
}

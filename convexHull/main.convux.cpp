#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparePoints(vector <int>& pointA , vector <int>& pointB){
    if (pointA[0] != pointB[0]) {
        return pointA[0] < pointB[0];
    } else {
        return pointA[1] < pointB[1];
    }
}

long long checkTurn(vector <int>& O,vector <int>& A, vector <int>&B){
    long long x1 = A[0] - O[0];
    long long y1 = A[1] - O[1];
    long long x2 = B[0] - O[0];
    long long y2 = B[1] - O[1];

    return x1 * y2 - x2 * y1;
}

vector<vector<int>> buildConvexHull(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 3) return points;
    sort(points.begin(), points.end(), comparePoints);
    vector<vector<int>> hull;

    
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && checkTurn(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

   
    int lowerHullSize = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        
        while (hull.size() > lowerHullSize && checkTurn(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}


int main() {

    vector<vector<int>> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<vector<int>> convexHull = buildConvexHull(points);

    cout << "Convex Hull Points:" << endl;
    for (const auto& point : convexHull) {
        cout << "(" << point[0] << ", " << point[1] << ")" << endl;
    }
    return 0;
}
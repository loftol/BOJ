#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double dist(double x1, double y1, double x2, double y2);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;

  double f, s;
  double M = 123412341234, x, y, MI = 0, tm;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> f >> s;
    v.emplace_back(f, s);
  }

  for (int i = 0; i < n; i++) {
    tm = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (tm < dist(v[i].first, v[i].second, v[j].first, v[j].second)) {
        tm = dist(v[i].first, v[i].second, v[j].first, v[j].second);
      }
    }
    if (tm < M) {
      M = tm;
      x = v[i].first, y = v[i].second;
    }
  }

  cout << fixed;
  cout.precision(10);

  cout << x << ' ' << y;
  return 0;
}

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
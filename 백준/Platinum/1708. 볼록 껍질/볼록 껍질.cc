#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<pii> points(n);
    for (auto& [x, y] : points) cin >> x >> y;

    auto OP = [&](pii a, pii b) {
        return (ll)a[0] * b[1] - (ll)a[1] * b[0];
    };

    auto ccw = [&](pii o, pii a, pii b) {
        pii u = { a[0] - o[0], a[1] - o[1] };
        pii v = { b[0] - o[0], b[1] - o[1] };
        ll op = OP(u, v);
        if (op) return (int)(op / abs(op));
        return 0;
    };

    sort(all(points));
    sort(points.begin() + 1, points.end(), [&](pii a, pii b) {return ccw(points[0], a, b) == 1; });
    points.push_back(points[0]);
    vector<pii> stk = {};
    for (pii c : points) {
        while (stk.size() > 1) {
            pii b = stk.back();
            stk.pop_back();
            pii a = stk.back();
            if (ccw(a, b, c) == 1) {
                stk.push_back(b);
                break;
            }
        }
        stk.push_back(c);
    }
    stk.pop_back();
    cout << stk.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}

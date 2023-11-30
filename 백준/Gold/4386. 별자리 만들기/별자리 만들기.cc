#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define pii array<int, 3>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y] = points[i];
        cin >> x >> y;
    }

    vector<tuple<double, int, int>> edges;

    for (int i = 0; i < n; i++) {
        auto [xi, yi] = points[i];
        for (int j = i + 1; j < n; j++) {
            auto [xj, yj] = points[j];
            double dx = xj - xi, dy = yj - yi;
            double d = sqrt(dx * dx + dy * dy);
            edges.push_back({ d, i, j });
        }
    }

    sort(all(edges));

    vector<int> par(n);
    iota(all(par), 0);

    function<int(int)> find = [&](int a) {
        if (a != par[a]) return par[a] = find(par[a]);
        return a;
    };

    function<bool(int, int)> uni = [&](int a, int b) {
        if (find(a) != find(b)) {
            par[par[a]] = par[b];
            return true;
        }
        return false;
    };
    double ans = 0;
    for (auto [d, u, v] : edges) {
        if (uni(u, v)) {
            ans += d;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while(t--) solve();
    
    return 0;
}
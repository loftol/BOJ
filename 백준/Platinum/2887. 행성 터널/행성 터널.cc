#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<ll, 4>
#define pii array<ll, 3>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<tii> node(n);
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        node[i] = { i, x, y, z };
    }

    vector<pii> edges;

    sort(all(node), [&](tii a, tii b) {
        if (a[1] == b[1]) return a < b;
        return a[1] < b[1];
        });

    for (int i = 1; i < n; i++) {
        ll u = node[i - 1][0];
        ll v = node[i][0];
        ll w = node[i][1] - node[i - 1][1];
        edges.push_back({ w, u, v });
    }

    sort(all(node), [&](tii a, tii b) {
        if (a[2] == b[2]) return a < b;
        return a[2] < b[2];
        });

    for (int i = 1; i < n; i++) {
        ll u = node[i - 1][0];
        ll v = node[i][0];
        ll w = node[i][2] - node[i - 1][2];
        edges.push_back({ w, u, v });
    }

    sort(all(node), [&](tii a, tii b) {
        if (a[3] == b[3]) return a < b;
        return a[3] < b[3];
        });

    for (int i = 1; i < n; i++) {
        ll u = node[i - 1][0];
        ll v = node[i][0];
        ll w = node[i][3] - node[i - 1][3];
        edges.push_back({ w, u, v });
    }

    sort(all(edges));
    vector<int> par(n + 1);
    iota(all(par), 0);

    function<int(int)> find = [&](int a) {
        if (par[a] != a) return par[a] = find(par[a]);
        return a;
    };
    
    function<bool(int, int)> uni = [&](int a, int b) {
        if (find(a) != find(b)) {
            par[par[b]] = par[a];
            return true;
        }
        return false;
    };
    ll ans = 0;
    for (auto [w, u, v] : edges) {
        assert(w >= 0);
        if (uni(u, v)) {
            ans += w;
        }
    }

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
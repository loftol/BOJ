#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18+7

void solve() {
    int n, lc, mc;
    cin >> n >> lc >> mc;
    vector<tii> edges;
    for (int i = 0; i < lc; i++) {
        int u, v, d; cin >> u >> v >> d;
        if (u > v) swap(u, v);
        edges.push_back({ u, v, d });
    }
    for (int i = 0; i < mc; i++) {
        int u, v, d; cin >> u >> v >> d;
        if (u > v) swap(u, v);
        edges.push_back({ v, u, -d });
    }
    vector<ll> dst(n + 1, MAX);
    dst[1] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, d] : edges) {
            if (dst[u] == MAX) continue;
            dst[v] = min(dst[v], dst[u] + d);
        }
    }
    vector<ll> dst2(n + 1);
    for (int i = 0; i < n; i++) {
        for (auto [u, v, d] : edges) {
            dst2[v] = min(dst2[u] + d, dst2[v]);
        }
    }
    
    for (auto [u, v, d] : edges) {
        if (dst2[u] + d < dst2[v] && dst2[v] < 0) {
            cout << -1 << '\n';
            return;
        }
        dst2[v] = min(dst2[u] + d, dst2[v]);
    }

    if (dst[n] == MAX)
        cout << -2 << '\n';
    else
        cout << dst[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1; //cin >> t;
    while (t--) solve();
}
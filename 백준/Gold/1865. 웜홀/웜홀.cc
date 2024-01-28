#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>

void solve() {
    int N, M, W; cin >> N >> M >> W;
    vector<tii> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({ u, v, w });
        edges.push_back({ v, u, w });
    }
    for (int i = 0; i < W; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({ u, v, -w });
    }

    vector<int> dst(N + 1);
    
    dst[1] = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (auto [u, v, w] : edges) {
            dst[v] = min(dst[u] + w, dst[v]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (auto [u, v, w] : edges) {
            if (dst[u] + w < dst[v] && dst[v] < 0) flag = true;
            dst[v] = min(dst[u] + w, dst[v]);
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; cin >> t;
    while (t--) solve();
}
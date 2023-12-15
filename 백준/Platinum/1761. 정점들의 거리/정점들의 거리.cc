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
    vector<vector<pii>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    vector<vector<pii>> dtable(30, vector<pii>(n + 1));
    vector<int> depth(n + 1);

    function<void(int, int)> dfs = [&](int here, int par) {
        depth[here] = depth[par] + 1;
        for (auto [next, ndst] : adj[here]) {
            if (next != par) {
                dtable[0][next] = { here, ndst };
                dfs(next, here);
            }
        }
    };

    dfs(1, 0);
    dtable[0][1] = { 1, 0 };
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            int par = dtable[i - 1][dtable[i - 1][j][0]][0];
            int dst = dtable[i - 1][dtable[i - 1][j][0]][1] + dtable[i - 1][j][1];
            dtable[i][j] = { par, dst };
        }
    }
    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        if (depth[a] > depth[b]) swap(a, b);
        ll ret = 0;
        int dd = depth[b] - depth[a];
        int exp = 0;
        while (dd) {
            if (dd & 1) {
                ret += dtable[exp][b][1];
                b = dtable[exp][b][0];
            }
            exp++;
            dd >>= 1;
        }
        for (exp = 29; exp >= 0; exp--) {
            if (dtable[exp][b][0] != dtable[exp][a][0]) {
                ret += dtable[exp][b][1] + dtable[exp][a][1];
                b = dtable[exp][b][0], a = dtable[exp][a][0];
            }
        }
        exp = 0;
        if (a != b) {
            ret += dtable[exp][b][1] + dtable[exp][a][1];
            b = dtable[exp][b][0], a = dtable[exp][a][0];
        }
        cout << ret << '\n';
    }


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

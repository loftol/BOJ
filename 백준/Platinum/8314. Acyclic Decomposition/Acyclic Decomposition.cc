#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define tll array<long long, 3>
#define mat vector<vector<int>>
#define pll array<ll, 2>

int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({ v, i });
    }
    vector<int> vst(n + 1), comp(n + 1);

    vector<int> edge1, edge2;

    function<void(int)> dfs = [&](int here) {
        vst[here] = 1;
        for (auto [next, idx] : adj[here]) {
            if (!vst[next]) {
                dfs(next);
                edge1.push_back(idx);
            }
            else {
                if (!comp[next])
                    edge2.push_back(idx);
                else
                    edge1.push_back(idx);
            }
        }
        comp[here] = 1;
    };

    for (int i = 1; i <= n; i++) {
        if (!vst[i]) dfs(i);
    }

    sort(all(edge1));
    sort(all(edge2));

    if (edge2.size() == 0) {
        cout << 1 << '\n';
        cout << edge1.size() << ' ';
        for (int i : edge1) cout << i << ' ';
        return;
    }

    cout << 2 << '\n';
    cout << edge1.size() << ' ';
    for (int i : edge1) cout << i << ' ';
    cout << '\n';
    cout << edge2.size() << ' ';
    for (int i : edge2) cout << i << ' ';


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
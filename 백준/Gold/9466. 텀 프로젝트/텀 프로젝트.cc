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
    vector<int> adj(n + 1);
    for (int i = 1; i <= n; i++) cin >> adj[i];
    vector<int> vst(n + 1), comp(n + 1);
    int ans = n;
    function<int(int)> dfs = [&](int here) {
        vst[here] = 1;
        int ret = 0;
        if (!comp[adj[here]] && vst[adj[here]])
            ret = adj[here];
        if (!vst[adj[here]])
            ret = dfs(adj[here]);

        if (ret) ans--;

        if (ret == here) ret = 0;
        comp[here] = 1;
        return ret;
    };

    for (int i = 1; i <= n; i++) {
        if (!vst[i]) dfs(i);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
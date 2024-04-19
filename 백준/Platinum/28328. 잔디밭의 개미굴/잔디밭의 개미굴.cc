#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD 998244353

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    adj[0].push_back(1);
    vector<vector<int>> table(2, vector<int>(n + 1));

    // dfs를 돌면서 넣을 수 있는 최댓값을 구한다.
    function<void(int, int)> dfs = [&](int here, int prev) {
        table[1][here] = 1;
        for(int next : adj[here]){
            if (next != prev) {
                dfs(next, here);
                table[0][here] += max(table[0][next], table[1][next]);
                table[1][here] += table[0][next];
            }
        }
    };

    dfs(1, 0);
    int cnt = 0;
    vector<vector<int>> vst(2, vector<int>(n + 1));
    // 안넣어도 되는 칸의 수를 구한다.
    function<void(int, int, int)> dfs2 = [&](int here, int prev, int fill) {

        vst[fill][here] = 1;
        if (fill == 0 && here != 0)
            cnt++;
        for (int next : adj[here]) {
            if (next != prev) {
                int M = max(table[0][next], table[1][next]);
                if (!fill && M == table[1][next]) {
                    if(!vst[1][next])
                        dfs2(next, here, 1);
                }
                if (fill || M == table[0][next]) {
                    if(!vst[0][next])
                        dfs2(next, here, 0);
                }
            }
        }
    };

    dfs2(0, 0, 0);
    /*
    for (int i = 1; i <= n; i++) {
        cout << vst[0][i] << ' ' << vst[1][i] << '\n';
    }*/

    cout << (ll)cnt * (n - 1) - (ll)cnt * (cnt - 1) / 2;
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
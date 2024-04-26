#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)998244353

void solve() {
    int n; cin >> n;
    vector<int> par(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    int cnt = 0;
    function<int(int, int)> dfs = [&](int here, int prev) {
        bool flag = true;
        int ccnt = adj[here].size();
        int MM = 0;
        for (int next : adj[here]) {
            int ret = dfs(next, here);
            if (ret == -1) {
                ccnt--;
            }
            MM = max(ret, MM);
        }
        if (ccnt < 3) flag = false;
        if (MM < 2) flag = false;
        if (flag && here != 1) {
            cnt++;
            return -1;
        }

        return ccnt;
    };

    dfs(1, 0);
    cout << cnt;
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
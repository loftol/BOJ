#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define tll array<long long, 3>
#define pll array<long long, 2>

int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto pmsearch = [&](int x) {
        vector<pii> stk = { {0, 1} };
        function<bool(int, int)> dfs = [&](int here, int par) {
            if (stk.empty()) return false;
            stk.back()[1]--;
            if (stk.back()[1] == 0) stk.pop_back();
            stk.push_back({ here, x });
            bool ret = true;
            for (int next : adj[here]) {
                if(next != par)
                    ret &= dfs(next, here);
            }
            if (stk.size() && stk.back()[0] == here) stk.pop_back();
            return ret;
        };
        return dfs(1, 0);
    };

    int l = 0, r = n - 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (pmsearch(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << '\n';
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
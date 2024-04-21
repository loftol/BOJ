#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<int, 3>
#define tll array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)1e9+7

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = false;
    // 매개변수 탐색을 쓸 수 있음
    auto solve = [&](int x) {
        //cout << "x = " << x << '\n';
        function<int(int, int)> dfs = [&](int here, int prev) {
            multiset<int> tails;
            for (int next : adj[here]) {
                if (prev != next) {
                    int ret = dfs(next, here);
                    if (ret == -1) return ret;
                    tails.insert(ret);
                }
            }
            //cout << "here = " << here << '\n';
            //for (int i : tails) cout << i << ' ';
            //cout << '\n';
            int ret = 0;
            while (tails.size()) {
                int now = *tails.rbegin();
                tails.erase(--tails.end());
                if (tails.empty()) {
                    if (ret == 0)
                        ret = now;
                    else if (ret <= x && here != 1) {
                        ret = now;
                    }
                    else {
                        return -1;
                    }
                    break;
                }
                auto iter = tails.upper_bound(x - now);
                if (iter == tails.begin()) {
                    if (ret == 0) {
                        ret = now;
                        continue;
                    }
                    else {
                        return -1;
                    }
                }
                tails.erase(--iter);
            }
            //cout << here << ' ' << ret + 1 << '\n';
            return ret + 1;
        };
        //cout << '\n';
        int u = dfs(1, 0);
        // 마지막에 +1 되는거 때문에 u <= x + 1로 확인해봐야 함
        return (u != -1) && (u <= x + 1);

    };

    int l = -1, r = n;
    while (l + 1 < r) {
        int mid = (l + r + 1) / 2;
        if (solve(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
        flag = true;
    }
    int lans = 1;
    for (int i = 1; i <= n; i++) {
        lans += (adj[i].size() + 1) / 2 - 1;
    }
    cout << lans << ' ' << r;
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
#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> ind(n + 1);

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int u, v; cin >> u;
        for (int i = 1; i < x; i++) {
            cin >> v;
            adj[u].push_back(v);
            ind[v]++;
            u = v;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
    }

    vector<int> order;

    while (q.size()) {
        int here = q.front();
        q.pop();
        order.push_back(here);
        for (int next : adj[here]) {
            ind[next]--;
            if (!ind[next]) {
                q.push(next);
            }
        }
    }

    if (order.size() != n) cout << 0;
    else {
        for (int i : order) cout << i << '\n';
    }

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
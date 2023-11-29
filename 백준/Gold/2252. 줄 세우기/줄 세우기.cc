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
    vector<int> ind(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ind[v]++;
        adj[u].push_back(v);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
    }

    while (q.size()) {
        int here = q.front();
        cout << here << ' ';
        q.pop();
        for (int next : adj[here]) {
            ind[next]--;
            if (ind[next] == 0) q.push(next);
        }
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
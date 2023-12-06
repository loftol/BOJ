#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define sii array<int, 6>
void solve() {
    int n, m, k; cin >> n >> m >> k;
    k--;
    vector<int> arr(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<int> v, w;
    vector<int> vst(n + 1);

    for (int i = 1; i <= n; i++) {
        if (vst[i]) continue;
        queue<int> q;
        q.push(i);
        vst[i] = 1;
        v.push_back(0), w.push_back(0);
        while (q.size()) {
            int here = q.front();
            q.pop();
            w.back()++; v.back() += arr[here];
            for (int next : adj[here]) {
                if (vst[next]) continue;
                vst[next] = 1;
                q.push(next);
            }
        }
    }

    vector<int> table(k + 1, -1);
    table[0] = 0;
    int x = v.size();
    int ans = 0;
    for (int i = 0; i < x; i++) {
        for (int j = k; j >= 0; j--) {
            if (table[j] == -1) continue;
            int nj = j + w[i];
            if (nj <= k) {
                table[nj] = max(table[nj], table[j] + v[i]);
                ans = max(ans, table[nj]);
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
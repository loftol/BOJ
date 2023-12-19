#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve(int n, int m) {
    int s, d; cin >> s >> d;
    vector<vector<pii>> adj(n);
    vector<vector<pii>> radj(n);
    for (int i = 0; i < m; i++) {
        int u, v, p; cin >> u >> v >> p;
        adj[u].push_back({ v, p });
        radj[v].push_back({ u, p });
    }
    vector<int> dst(n, INF);
    priority_queue<pii> pq;
    pq.push({ 0, s });
    dst[s] = 0;
    while (pq.size()) {
        auto [hdst, here] = pq.top();
        pq.pop();
        hdst *= -1;
        if (hdst > dst[here]) continue;
        for (auto [next, ndst] : adj[here]) {
            ndst += dst[here];
            if (ndst < dst[next]) {
                pq.push({ -ndst, next });
                dst[next] = ndst;
            }
        }
    }
    vector<vector<int>> block(n, vector<int>(n));
    queue<pii> q;
    q.push({ d, dst[d] });
    vector<int> vst(n);
    while (q.size()) {
        auto [here, hdst] = q.front();
        q.pop();
        for (auto [prev, pdst] : radj[here]) {
            pdst += dst[prev];
            if (pdst == hdst) {
                if (!vst[prev]) {
                    vst[prev] = 1;
                    q.push({ prev, dst[prev] });
                }
                block[prev][here] = 1;
            }
        }
    }
    dst = vector<int>(n, INF);
    pq.push({ 0, s });
    dst[s] = 0;
    while (pq.size()) {
        auto [hdst, here] = pq.top();
        pq.pop();
        hdst *= -1;
        if (hdst > dst[here]) continue;
        for (auto [next, ndst] : adj[here]) {
            ndst += dst[here];
            if (ndst < dst[next] && !block[here][next]) {
                pq.push({ -ndst, next });
                dst[next] = ndst;
            }
        }
    }
    if (dst[d] == INF) cout << -1 << '\n';
    else cout << dst[d] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve(n, m);
    }
}

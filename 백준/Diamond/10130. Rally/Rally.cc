#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define MAX (int)1e8
#define ll long long
#define tii array<int, 3>
#define pll array<ll, 2>
#define MOD 998244353
vector<int> adj[500002], radj[500002];
int ind[500002], outd[500002], rdst[500002],ldst[500002], cnt[500002];
int seg[2000002];
int S;

void update(int idx, int val) {
    idx += S;
    seg[idx] = val;
    for (idx >>= 1; idx > 0; idx >>= 1)
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
};

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n + 2; i++) {
        ind[i] = 0;
        outd[i] = 0;
        ldst[i] = -1;
        rdst[i] = -1;
        cnt[i] = 0;
    }
    for (int i = 0; i < 2000002; i++) seg[i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
        ind[v]++;
        outd[u]++;
    }
    ind[n + 1] = n;
    outd[0] = n;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            adj[0].push_back(i);
            radj[i].push_back(0);
            ind[i]++;
            outd[0]++;
        }
        if (outd[i] == 0) {
            adj[i].push_back(n + 1);
            radj[n + 1].push_back(i);
            ind[n + 1]++;
            outd[i]++;
        }
    }
    queue<int> q; q.push(n + 1);
    while (q.size()) {
        int here = q.front();
        q.pop();
        for (int next : radj[here]) {
            if (++cnt[next] == outd[next]) {
                q.push(next);
            }
            rdst[next] = max(rdst[here] + 1, rdst[next]);
        }
    }

    S = bit_ceil((unsigned int)(n + 2));

    
    for (int i = 0; i < n + 2; i++) cnt[i] = 0;
    int ans = n + 1, ansi = -1;
    q.push(0);
    while (q.size()) {
        int here = q.front();
        q.pop();
        update(here, 0);
        int hans = max({ seg[1], ldst[here] - 1, rdst[here] - 1 });
        if (hans < ans && here != 0 && here != n + 1) {
            ans = hans;
            ansi = here;
        }
        for (int next : adj[here]) {
            if (seg[S + next] < ldst[here] + rdst[next] + 1)
                update(next, ldst[here] + rdst[next] + 1);
        }
        for (int next : adj[here]) {
            if (++cnt[next] == ind[next])
                q.push(next);
            ldst[next] = max(ldst[here] + 1, ldst[next]);
        }
    }

    cout << ansi << ' ' << ans << '\n';
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
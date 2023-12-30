#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n, q; cin >> n >> q;
    vector<tii> invs(n);
    for (int i = 0; i < n; i++) {
        cin >> invs[i][0] >> invs[i][1];
        invs[i][2] = i;
    }

    // Sa <= Eb <= Ea 이면 a -> b 연결 (거꾸로 가는 것)

    sort(all(invs), [&](tii a, tii b) {
        if (a[1] == b[1]) return a[0] > b[0];
        else return a[1] < b[1];
        });

    vector<tii> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && stk.back()[1] == invs[i][1]) {
            stk.pop_back();
        }
        stk.push_back(invs[i]);
    }
    vector<int> endpoints;
    for (auto [s, e, i] : stk) endpoints.push_back(e);
    int m = stk.size();
    int S = bit_ceil((unsigned int)m);

    vector<tii> seg(2 * S);
    for (int i = 0; i < m; i++) 
        seg[i + S] = stk[i];
    
    for (int SS = S / 2; SS > 0; SS /= 2)
        for (int i = SS; i < 2 * SS; i++) 
            seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    
    auto query = [&](int l, int r) {
        tii ret = { (int)1e9 + 1, 0, 0 };
        for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ret = min(ret, seg[l++]);
            if (r & 1 ^ 1) ret = min(ret, seg[r--]);
        }
        return ret;
    };

    int j = 0;
    vector<vector<int>> dtable(31, vector<int>(n, -1));

    for (auto [s, e, i] : invs) {
        int ss = lower_bound(all(endpoints), s) - endpoints.begin();
        int ee = upper_bound(all(endpoints), e) - endpoints.begin() - 1;
        if (ee >= ss) {
            auto [_, __, x] = query(ss, ee);
            dtable[0][i] = x;
        }
        else {
            dtable[0][i] = i;
        }
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j < n; j++) {
            dtable[i][j] = dtable[i - 1][dtable[i - 1][j]];
        }
    }

    sort(all(invs), [&](tii a, tii b) {
        return a[2] < b[2];
    });

    while (q--) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (u == v) {
            cout << 0 << '\n';
            continue;
        }
        else if (invs[u][1] >= invs[v][0] && invs[u][1] <= invs[v][1]) {
            cout << 1 << '\n';
            continue;
        }
        auto [s, e, _] = invs[u];
        int d = 0;
        for (int exp = 30; exp >= 0; exp--) {
            int nv = dtable[exp][v];
            auto [l, r, __] = invs[nv];
            if (l <= e) continue;
            v = nv;
            d += (1 << exp);
        }
        if (invs[v][0] > e) {
            d++;
            v = dtable[0][v];
        }
        
        if (invs[v][0] == s && invs[v][1] == e) {
            cout << d << '\n';
        }
        else if (invs[v][0] <= e && e <= invs[v][1]) {
            cout << d + 1 << '\n';
        }
        else {
            cout << "impossible\n";
        }
    }
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
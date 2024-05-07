#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pdd array<double, 2>
#define qii array<int, 4>
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)998244353

void solve() {
    int n; cin >> n;
    vector<pii> points(n);
    for (auto& [i, j] : points) {
        double x, y; cin >> x >> y;
        i = x, j = y;
    }
    vector<int> chk(n);

    priority_queue<qii> pq;
    for (int u = 0; u < n; u++) {
        for (int v = u+1; v < n; v++) {
            auto [ui, uj] = points[u];
            auto [vi, vj] = points[v];
            int di = abs(ui - vi);
            int dj = abs(uj - vj);
            int md = min(di, dj);
            int Md = max(di, dj);
            pq.push({ -Md, -md, u, v });
        }
    }
    cout << "Yes\n";
    while (pq.size()) {
        auto [Md, md, i, j] = pq.top();
        pq.pop();
        int u = i;
        int v = j;
        auto [ui, uj] = points[u];
        auto [vi, vj] = points[v];
        if (chk[i] || chk[j]) continue;
        chk[i] = chk[j] = 1;
        double ci = (double)(ui + vi) / 2;
        double cj = (double)(uj + vj) / 2;
        double MD = Md * (-0.5);
        cout << fixed;
        cout.precision(3);
        cout << ci - MD << ' ' << cj - MD << ' ' << ci + MD << ' ' << cj + MD << '\n';
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

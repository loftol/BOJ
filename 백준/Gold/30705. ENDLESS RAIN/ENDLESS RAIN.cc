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
    int n, m; cin >> n >> m;
    vector<int> par(n + 1); iota(all(par), 0);
    vector<int> l(n), r(n + 1); iota(all(r), 0);

    function<int(int)> find = [&](int a) {
        if (par[a] != a) return par[a] = find(par[a]);
        return a;
    };

    function<bool(int, int)> uni = [&](int a, int b) {
        if (find(a) != find(b)) {
            par[par[b]] = par[a];
            r[par[a]] = max(r[par[a]], r[par[b]]);
            return true;
        }
        return false;
    };
    int a = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        a++;
        int u, v; cin >> u >> v;
        int cnt = 0;
        int x = u;
        while (x < v) {
            if (x == par[x]) {
                cnt++;
                uni(x + 1, x);
            }
            x = r[find(x)];
        }
        if (a >= cnt) a -= cnt;
        else {
            ans += cnt - a;
            a = 0;
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
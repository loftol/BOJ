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
    vector<int> par(n); iota(all(par), 0);

    function<int(int)> find = [&](int a) {
        if (par[a] != a) return par[a] = find(par[a]);
        return a;
    };

    function<bool(int, int)> uni = [&](int a, int b) {
        if (find(a) != find(b)) {
            par[par[b]] = par[a];
            return true;
        }
        return false;
    };

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (!uni(u, v)) {
            cout << i;
            return;
        }

    }
    cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
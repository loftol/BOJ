#include<iostream>
#include<string>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
#include<array>
#include<set>
#include<functional>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>


void solve() {
    int n, m; cin >> n >> m;
    vector<tii> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({ w, u, v });
    }

    sort(all(edges));

    vector<int> par(n + 1);
    iota(all(par), 0);
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
    int ans = 0;
    int last = 0;
    for (auto [w, u, v] : edges) {
        if (uni(u, v)) {
            ans += w;
            last = w;
        }
    }
    cout << ans - last;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
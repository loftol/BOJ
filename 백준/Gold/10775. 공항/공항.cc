#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int g, p; cin >> g >> p;
    vector<int> par(g + 1);
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
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        if (find(x)) {
            ans++;
            uni(find(x) - 1, find(x));
        }
        else break;
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
#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(m); for (int& i : arr) cin >> i;
    vector<int> par(m + 1); iota(all(par), 0);
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
    sort(all(arr));
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        int pos = upper_bound(all(arr), x) - arr.begin();
        int newPos = find(pos);
        uni(newPos + 1, pos);
        cout << arr[newPos] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
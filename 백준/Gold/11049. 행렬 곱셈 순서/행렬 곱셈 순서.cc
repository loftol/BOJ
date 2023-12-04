#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<pii> mats(n);
    for (auto& [a, b] : mats) cin >> a >> b;
    vector<vector<int>> table(n, vector<int>(n, -1));

    function<int(int, int)> dnc = [&](int l, int r) {
        int& ret = table[l][r];
        if (ret != -1) return ret;
        if (l == r) return ret = 0;
        for (int i = l; i < r; i++) {
            if (ret == -1) {
                ret = dnc(l, i) + dnc(i + 1, r) + mats[l][0] * mats[i][1] * mats[r][1];
            }
            else {
                ret = min(ret, dnc(l, i) + dnc(i + 1, r) + mats[l][0] * mats[i][1] * mats[r][1]);
            }
        }
        return ret;
    };

    cout << dnc(0, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
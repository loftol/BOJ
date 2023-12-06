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
    int n; cin >> n;
    vector<tii> cost(n);
    for (auto& [r, g, b] : cost) cin >> r >> g >> b;
    vector<vector<vector<int>>> table(3, vector<vector<int>>(n, vector<int>(3, 1e9)));
    for (int i = 0; i < 3; i++) {
        table[i][0][i] = cost[0][i];
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < 3; k++) {
                if (table[i][j][k] != -1) {
                    int kk = (k + 1) % 3;
                    table[i][j + 1][kk] = min(table[i][j + 1][kk], table[i][j][k] + cost[j + 1][kk]);
                    kk = (kk + 1) % 3;
                    table[i][j + 1][kk] = min(table[i][j + 1][kk], table[i][j][k] + cost[j + 1][kk]);
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 3; i++) {
        int kk = i;
        kk = (kk + 1) % 3;
        ans = min(ans, table[i][n - 1][kk]);
        kk = (kk + 1) % 3;
        ans = min(ans, table[i][n - 1][kk]);
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
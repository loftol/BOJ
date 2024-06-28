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

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<vector<int>> seat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> seat[i][j];
            seat[i][j] += i * d;
        }
        sort(all(seat[i]));
        if (i) {
            for (int j = 0; j < m; j++) {
                if (seat[i - 1][j] >= seat[i][j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    
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
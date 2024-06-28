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
#define MOD (ll)1e9 + 7

void solve() {
    ll n, m, d; cin >> n >> m >> d;
    vector<vector<int>> seat(n, vector<int>(m));
    ll total = 1;
    for (int j = 1; j <= m; j++) {
        total *= j;
        total %= MOD;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> seat[i][j];
        }
        sort(all(seat[i]));
        ll subcnt = 1;
        if (i) {
            for (int j = 0; j < m; j++) {
                subcnt *= max(0LL, ((ll)(lower_bound(all(seat[i - 1]), seat[i][j] + d) - seat[i - 1].begin()) - j));
                subcnt %= MOD;
            }
        }
        total *= subcnt;
        total %= MOD;
    }
    cout << total;
    
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
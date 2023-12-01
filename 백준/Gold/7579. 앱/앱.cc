#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> b(n), c(n);
    for (ll& a : b) cin >> a;
    for (ll& a : c) cin >> a;

    vector<ll> table(m + 1, -1);
    table[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (table[j] == -1) continue;
            int nj = min((int)(j + b[i]), m);
            if (table[nj] == -1) table[nj] = table[j] + c[i];
            else table[nj] = min(table[nj], table[j] + c[i]);
        }
    }

    cout << table[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
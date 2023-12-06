#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define pii array<int, 2>
#define tii array<int, 3>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
#define mat vector<vector<ll>>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            seats[i] <<= 1;
            char c; cin >> c;
            if (c == 'x') {
                seats[i] |= 1;
            }
        }
    }

    vector<int> table((1 << m));
    
    for (int i = 0; i < (1 << m); i++) {
        if (i & (i << 1)) continue;
        if (i & (seats[0])) continue;
        table[i] = popcount((unsigned int)i);
    }

    for (int j = 1; j < n; j++) {
        vector<int> newTable(1 << m, -1);
        for (int k = 0; k < (1 << m); k++) {
            if (table[k] == -1) continue;
            for (int i = 0; i < (1 << m); i++) {
                if (i & (i << 1)) continue;
                if (i & seats[j]) continue;
                if (k & (i << 1)) continue;
                if (k & (i >> 1)) continue;
                newTable[i] = max(newTable[i], popcount((unsigned int)i) + table[k]);
            }
        }
        table = newTable;
    }

    int ans = 0;

    for (int i = 0; i < (1 << m); i++) {
        ans = max(ans, table[i]);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; cin >> t;
    while(t--) solve();
    
    return 0;
}
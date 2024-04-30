#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)998244353

void solve() {
    int r, g, b; cin >> r >> g >> b;
    int ans = 1000;
    for (int x = 0; x <= 100; x++) {
        int rr = max(0, (r - x + 2) / 3);
        int gg = max(0, (g - x + 2) / 3);
        int bb = max(0, (b - x + 2) / 3);
        ans = min(x + rr + gg + bb, ans);
    }
    
    cout << ans;
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

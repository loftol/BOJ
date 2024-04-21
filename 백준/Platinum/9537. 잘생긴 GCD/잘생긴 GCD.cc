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
#define MOD (ll)1e9+7

void solve() {
    int m; cin >> m;
    vector<ll> a(m);
    for (ll& i : a) cin >> i;

    vector<pll> stk;

    ll ans = 1;
    for (int i = 0; i < m; i++) {
        vector<pll> newstk;
        for (auto [g, l] : stk) {
            pll p = { gcd(g, a[i]), l + 1 };
            if (newstk.size() && newstk.back()[0] == p[0])
                newstk.back() = max(newstk.back(), p);
            else
                newstk.push_back(p);
        }
        newstk.push_back({ a[i], 1LL });
        swap(stk, newstk);
        for (auto [g, l] : stk) {
            //cout << g << ' ' << l << '\n';
            ans = max(ans, g * l);
        }
        
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1; cin >> t;
    while (t--) solve();
}
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
    int k=0, p=0;
    string s; cin >> s;
    int ans = 0;
    for (char c : s) {
        if (c == 'K') {
            if (k == 0) ans++;
            else k--;
            p++;
        }
        else if (c == 'P') {
            if (p == 0) ans++;
            else p--;
            k++;
        }
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

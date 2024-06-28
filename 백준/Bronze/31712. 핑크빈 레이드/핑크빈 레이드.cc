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
    int cu, du; cin >> cu >> du;
    int cd, dd; cin >> cd >> dd;
    int cp, dp; cin >> cp >> dp;

    int h; cin >> h;

    int t = 0;
    while (h > 0) {
        if (t % cu == 0) h -= du;
        if (t % cd == 0) h -= dd;
        if (t % cp == 0) h -= dp;
        t++;
    }

    cout << t - 1;
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
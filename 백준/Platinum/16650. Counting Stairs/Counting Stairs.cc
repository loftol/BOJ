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
ll P[100001][451];

void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = n % 2; i <= sqrt(n); i+=2) {
        int nn = n - i * i;
        nn /= 2;
        ans += P[nn][i];
        if (nn == 0) ans++;
    }
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // N개를 K개의 자연수로 분할하는 방법
    
    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j <= min(i, 450); j++) {
            if (j == 1) P[i][j] = 1;
            else if (j == i) P[i][j] = 1;
            else {
                P[i][j] = P[i - 1][j - 1] + P[i - j][j];
                P[i][j] %= MOD;
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j <= 450; j++) {
            P[i][j] += P[i][j-1];
            P[i][j] %= MOD;
        }
    }


    int t = 1; cin >> t;
    while (t--) solve();
}
#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    ll a, b; cin >> a >> b;
    auto cnt = [](ll a) {
        ll x = 1;
        ll ret = 0;
        while (x <= a) {
            x <<= 1;
            ll ub = (a / x * x + x);
            ret += ub / 2;
            ll sub = a % x;
            sub = x / 2 - max(sub - x / 2 + 1, 0LL);
            ret -= sub;
        }
        return ret;
    };
    cout << cnt(b) - cnt(a - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
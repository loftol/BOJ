#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define tll array<long long, 3>
#define pll array<long long, 2>

int MOD = 998244353;

void solve() {
    ll n, s; cin >> n >> s;
    vector<ll> t(n); for (ll& i : t) cin >> i;
    deque<tll> dq;
    ll init = 0;
    for (int i = 1; i < n; i++) {
        t[i] = max(t[i - 1] + 1, t[i]);
    }

    for (int i = 0; i < n; i++) {
        while (dq.size() && dq.back()[0] + (i - dq.back()[1] - 1) < t[i]) {
            init = dq.back()[1] + 1;
            dq.pop_back();
        }
        ll ret = t[i] + 2 * s + (i - init);
        if (dq.size()) {
            ret = min(ret, dq.back()[0] + 2 * s + 2 * (i - dq.back()[1] - 1));
        }
        while (dq.size() && dq.front()[0] + (i - dq.front()[1]) > ret) {
            dq.pop_front();
        }
        dq.push_front({ ret, i, 0});
    }
    cout << dq.front()[0];
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
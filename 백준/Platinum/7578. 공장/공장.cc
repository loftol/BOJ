#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    unordered_map<int, int> mp;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        mp[val] = i;
    }

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        val = mp[val];
        arr[i] = val;
    }

    int S = 1; S = bit_ceil((unsigned)n);
    vector<ll> seg(2 * S);
    auto update = [&](int idx, ll val) {
        idx += S;
        seg[idx] = val;
        for (idx >>= 1; idx > 0; idx >>= 1)
            seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    };
    auto query = [&](int l, int r) {
        ll ret = 0;
        for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ret += seg[l++];
            if (r & 1 ^ 1) ret += seg[r--];
        }
        return ret;
    };
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += query(arr[i], n - 1);
        update(arr[i], 1);
    }
    cout << ans << '\n';
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

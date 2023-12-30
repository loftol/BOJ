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
    vector<int> arr(n);
    vector<pii> ord(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ord[i] = { arr[i], i };
    }
    sort(all(ord), greater<>());
    
    int S = bit_ceil((unsigned int) n);
    vector<int> seg(2 * S);

    auto update = [&](int idx, int val) {
        idx += S;
        seg[idx] = val;
        while (idx >>= 1)
            seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    };

    auto query = [&](int l, int r) {
        int ret = 0;
        for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ret += seg[l++];
            if (r & 1 ^ 1) ret += seg[r--];
        }
        return ret;
    };
    int ans = 0;
    for (auto [val, idx] : ord) {
        double l = query(0, idx);
        double r = query(idx, n - 1);
        if ((l == 0 && r > 0) || (l > 0 && r == 0)) ans++;
        else if (l > 0 && r > 0 && max(l / r, r / l) > 2) {
            ans++;
        }
        update(idx, 1);
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
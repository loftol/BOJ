#include<bits/stdc++.h>
#include<array>
#include<bit>
#define all(v) v.begin(),v.end()
using namespace std;
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<int, 3>
#define ll long long
#define MOD 998244353
#define MIN (ll)-4e18

void solve() {
    int n; cin >> n;
    ll total = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr.push_back(arr[i]);
        total += arr[i];
    }
    vector<ll> stk;
    for (int i = 2 * n - 2; i >= n; i--) {
        while (stk.size() && arr[stk.back()] >= arr[i]) stk.pop_back();
        stk.push_back(i);
    }

    vector<ll> llen(n);
    vector<ll> rlen(n);
    vector<ll> val(n);
    for (int i = n - 1; i >= 0; i--) {
        while (stk.size() && arr[stk.back()] >= arr[i]) {
            llen[stk.back() % n] = max(llen[stk.back() % n], stk.back() - i);
            stk.pop_back();
        }
        if (stk.size()) {
            val[i] = arr[i] - arr[stk.back()];
            rlen[i] = stk.back() - i;
        }
        stk.push_back(i);
    }
    vector<ll> ans(n + 1);
    for (int i = 0; i < n; i++) {
        ans[rlen[i]] += val[i];
        ans[llen[i] + rlen[i]] -= val[i];
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
        total -= ans[i];
        cout << total << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
}

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
    int n; cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(all(arr), [&](pii a, pii b) {
        return a[1] < b[1];
        });

    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b) {
        return arr[a] > arr[b];
        });

    set<int> s;
    vector<pii> intervals;
    for (int i : idx) {
        s.insert(arr[i][1]);
        auto lb = s.lower_bound(arr[i][1] - arr[i][0]);
        int l = *lb;
        auto rb = s.upper_bound(arr[i][1] + arr[i][0]);
        rb--;
        int r = *rb;
        intervals.push_back({ l, r });
    }

    sort(all(intervals));
    vector<pii> stk;
    for (auto [l, r] : intervals) {
        if (stk.size() && stk.back()[1] >= l) 
            stk.back()[1] = max(r, stk.back()[1]);
        else 
            stk.push_back({ l, r });
    }
    int ans = 0;
    for (auto [l, r] : stk)
        ans += r - l;

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
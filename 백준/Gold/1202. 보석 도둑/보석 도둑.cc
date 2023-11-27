#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<pii> jewels(n);
    vector<int> c(k), vst(k);
    for (int i = 0; i < n; i++) {
        cin >> jewels[i][0] >> jewels[i][1];
    }
    sort(all(jewels), greater<>());
    priority_queue<int> pq;
    for (int& i : c) cin >> i;
    sort(all(c));
    ll ans = 0;
    for (int i : c) {
        while (jewels.size() && jewels.back()[0] <= i) {
            pq.push({ jewels.back()[1] });
            jewels.pop_back();
        }
        if (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while(t--) solve();
    
    return 0;
}
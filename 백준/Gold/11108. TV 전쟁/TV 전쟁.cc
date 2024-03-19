#include<bits/stdc++.h>
#include<array>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<int, 3>
#define tll array<ll, 3>
#define bs bitset<32>
#define INF 1e9
void solve() {
    int n; cin >> n;
    vector<tii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][1] += arr[i][0];
    }
    sort(all(arr), [&](tii a, tii b) {
        return a[1] < b[1];
        });

    vector<int> table(11000);
    int d = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        auto [s, e, w] = arr[i];
        while (d <= s) {
            table[d] = max(table[d], table[d - 1]);
            d++;
        }
        table[e] = max(table[e], table[s] + w);
        ans = max(ans, table[e]);
    }
    
    
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; cin >> t;
    while (t--) solve();
}
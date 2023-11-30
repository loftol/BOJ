#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pii> arr(n);
    for (auto& [a, b] : arr) cin >> a >> b;
    sort(all(arr));

    vector<int> table;
    vector<int> track(n);
    for (int i = 0; i < n; i++) {
        auto [_, x] = arr[i];
        auto iter = lower_bound(all(table), x);
        track[i] = iter - table.begin();
        if (iter != table.end()) table[track[i]] = x;
        else table.push_back(x);
    }
    cout << n - table.size() << '\n';
    int m = table.size() - 1;
    int val = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i][1] < val && track[i] == m) {
            m--;
            arr[i][1] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i][1] != -1)
            cout << arr[i][0] << '\n';
    }
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
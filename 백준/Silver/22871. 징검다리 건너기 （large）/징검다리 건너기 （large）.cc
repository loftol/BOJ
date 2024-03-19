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
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dst(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dst[i][j] = (j - i) * (1 + abs(arr[i] - arr[j]));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dst[0][i] = min(dst[0][i], max(dst[0][j], dst[j][i]));
        }
    }

    cout << dst[0][n - 1];
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
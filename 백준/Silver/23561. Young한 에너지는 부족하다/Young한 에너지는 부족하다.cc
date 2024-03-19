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
    vector<int> arr(3 * n);
    for (int& i : arr) cin >> i;
    sort(all(arr));
    cout << arr[2 * n - 1] - arr[n];
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
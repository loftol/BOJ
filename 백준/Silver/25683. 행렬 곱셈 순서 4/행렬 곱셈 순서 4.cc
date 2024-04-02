#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<ll, 2>
#define tll array<ll, 3>
#define bs bitset<32>
#define TB (*table)
#define MAX (int)1e9

void solve() {
    int n; cin >> n;
    ll total = 0;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        arr[i] = { a, b };
    }
    ll bk = arr.back()[1];
    arr.pop_back();
    while(arr.size()) {
        total += arr.back()[0] * arr.back()[1] * bk;
        arr.pop_back();
    }

    cout << total;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;// cin >> t;
    while (t--) solve();
}
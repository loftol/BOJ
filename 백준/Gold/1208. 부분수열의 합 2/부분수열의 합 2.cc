#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
using namespace std;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    vector<int> sums1, sums2;
    unordered_map<int, int> mp1, mp2;
    mp1[0] = 1;
    mp2[0] = 1;
    for (int i = 1; i < (1 << (n / 2)); i++) {
        int sum = 0;
        int bi = i, u = 0;
        while (bi >> u) {
            if ((bi >> u) & 1) {
                sum += arr[u];
            }
            u++;
        }
        if (mp1.find(sum) != mp1.end()) mp1[sum]++;
        else mp1[sum] = 1;
    }
    for (int i = 1; i < (1 << ((n + 1) / 2)); i++) {
        int sum = 0;
        int bi = i, u = 0;
        while (bi >> u) {
            if ((bi >> u) & 1) {
                sum += arr[u + n / 2];
            }
            u++;
        }
        if (mp2.find(sum) != mp2.end()) mp2[sum]++;
        else mp2[sum] = 1;
    }

    ll ans = 0;

    for (auto [val, cnt] : mp1) {
        int pair_val = s - val;
        ans += (ll)cnt * mp2[pair_val] ;
    }
    if (s == 0) ans--;
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
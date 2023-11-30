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
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    int l = 0, r = n - 1;
    tii ans = { l, r, abs(arr[r] + arr[l]) };
    while (l < r) {
        int val = arr[r] + arr[l];
        if (abs(val) < ans[2]) {
            ans = { l, r, abs(val) };
        }
        if (val > 0) r--;
        else if (val < 0) l++;
        else break;
    }

    cout << arr[ans[0]] << ' ' << arr[ans[1]];
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
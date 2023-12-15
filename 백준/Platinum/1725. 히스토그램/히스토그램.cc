#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<ll> arr(n); for (ll& i : arr) cin >> i;

    function<ll(int, int)> dnc = [&](int l, int r) {
        if (l == r) return arr[l];
        int ml = (l + r) / 2, mr = (l + r) / 2 + 1;
        ll ans = max(dnc(l, ml), dnc(mr, r));
        ll h = 1e9+1;
        while (true) {
            h = min({ h, arr[ml], arr[mr] });
            ans = max(ans, h * (mr - ml + 1));
            if (mr < r && (ml == l || arr[ml - 1] <= arr[mr + 1])) mr++;
            else if (ml > l) ml--;
            else break;
        }
        return ans;
    };

    cout << dnc(0, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}

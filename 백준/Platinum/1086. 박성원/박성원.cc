#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define pii array<int, 2>
#define tii array<int, 3>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
#define mat vector<vector<ll>>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        reverse(all(arr[i]));
    }

    int k; cin >> k;

    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        int ten = 1;
        int val = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            val += (arr[i][j] - '0') * ten;
            val %= k;
            ten *= 10;
            ten %= k;
        }
        v[i] = val;
        w[i] = arr[i].size();
    }

    function<ll(int, int)> fast_pow = [&](int n, int a) {
        if (n == 0) return 1LL;
        ll ret = fast_pow(n / 2, a);
        ret *= ret * (n % 2 ? a : 1);
        ret %= k;
        return ret;
    };
    vector<ll> powers(5001);
    for (int i = 0; i <= 5000; i++) {
        powers[i] = fast_pow(i, 10);
    }

    vector<vector<ll>> table((1 << n), vector<ll>(k, -1));
    function<ll(int, int, int)> tsp = [&](int bitset, int mod, int idx) {
        ll& ret = table[bitset][mod];
        if (ret != -1) return ret;
        
        if (bitset == (1 << n) - 1) {
            if (mod == 0) return ret = 1;
            else return ret = 0;
        }
        
        ret = 0;

        for (int i = 0; i < n; i++) {
            if (bitset & (1 << i)) continue;
            ret += tsp(bitset | (1 << i), (mod + v[i] * powers[idx]) % k, idx + w[i]);
        }
        return ret;
    };

    ll q = tsp(0, 0, 0);
    ll p = 1;
    for (int i = 1; i <= n; i++) p *= i;
    ll g = gcd(p, q);
    q /= g, p /= g;
    cout << q << '/' << p;
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
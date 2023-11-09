#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <bit>

using namespace std;

#define all(x) x.begin(),x.end()
#define tii array<int, 3>
#define pii pair<int, int>
#define ll long long
#define inv 500

int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n);

    ll sum = 0;

    for (ll& i : a) cin >> i;

    bool pos = true;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
        if (a[i] > sum) pos = false;
    }

    if (!pos) cout << -1;
    else {
        cout << (sum - a[n - 1]) / x;
    }


    return 0;
}
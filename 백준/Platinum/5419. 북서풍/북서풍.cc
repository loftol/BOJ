#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;
int S = 1, n;
vector<pii> arr;
vector<int> seg;

void update(int idx, ll val) {
    idx += S;
    seg[idx] = val;
    while (idx >>= 1) {
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
}

void init() {
    while (S < n) S <<= 1;
    seg = vector<int>(S * 2);
}

ll query(int l, int r) {
    ll ret = 0;
    for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1 ^ 1) ret += seg[r--];
    }
    return ret;
}

void solve() {
    S = 1;
    cin >> n;
    arr = vector<pii>(n);
    for (auto& [x, y] : arr) { cin >> x >> y; y *= -1; }
    sort(all(arr));
    int idx = 0;
    for (auto& [x, y] : arr) x = idx++;
    init();
    
    sort(all(arr), [](pii a, pii b) {
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    });

    int M = 0;
    ll sum = 0;
    for (auto [x, y] : arr) {
        sum += query(0, x);
        update(x, 1);
    }

    cout << sum << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <bit>

#define ll long long
#define vi vector<int>
#define mat vector<vi>
#define pii pair<int, int>
#define tii array<int, 3>
#define all(v) v.begin(),v.end()

using namespace std;

vector<ll> seg;

int n, S = 1, m, k;

void init() {
	S = bit_ceil((unsigned int)n);
	seg = vector<ll>(2 * S);

	for (int i = 0; i < n; i++)
		cin >> seg[S + i];
	
	for (int SS = S / 2; SS > 0; SS /= 2)
		for (int i = SS; i < 2 * SS; i++)
			seg[i] = seg[2 * i] + seg[2 * i + 1];
}

void update(int idx, ll val) {
	idx += S;
	seg[idx] = val;
	for (idx /= 2; idx > 0; idx /= 2) 
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

ll query(int l, int r) {
	l += S;
	r += S;
	ll ret = 0;
	while (l <= r) {
		if (l & 1)
			ret += seg[l++];
		if (r & 1 ^ 1)
			ret += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	init();
	m += k;
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << query(b - 1, c - 1) << '\n';
		}
	}

	return 0;
}
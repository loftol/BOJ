#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>
#define all(x) x.begin(), x.end()

void solve() {
	int q; cin >> q;
	int n = 1e6, S = 1;
	S = bit_ceil((unsigned int)n);
	vector<int> seg(2 * S);

	auto update = [&](int idx, int val) {
		idx += S;
		seg[idx] += val;
		for (idx >>= 1; idx > 0; idx >>= 1)
			seg[idx] = seg[idx * 2] + seg[2 * idx + 1];
	};

	auto BSquery = [&](int val) {
		int idx = 1;
		while (idx < S) {
			idx *= 2;
			if (seg[idx] < val) val -= seg[idx++];
		}
		return idx - S;
	};

	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int b; cin >> b;
			int idx = BSquery(b);
			update(idx, -1);
			cout << idx + 1 << '\n';
		}
		else {
			int b, c; cin >> b >> c;
			update(b - 1, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; //cin >> t;
	while (t--) solve();

	return 0;
}
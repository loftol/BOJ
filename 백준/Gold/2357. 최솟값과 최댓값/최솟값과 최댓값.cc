#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>
#define all(x) x.begin(), x.end()

void solve() {
	int n, m; cin >> n >> m;
	int S = 1;
	S = bit_ceil((unsigned int)(n+1));
	vector<pii> seg(2 * S, array{(int)1e9+1, 0});


	auto oper = [&](pii a, pii b) {
		return array{ min(a[0], b[0]), max(a[1], b[1]) };
	};

	auto update = [&](int idx, int val) {
		idx += S;
		seg[idx] = {val, val};
		for (idx >>= 1; idx > 0; idx >>= 1)
			seg[idx] = oper(seg[idx * 2],seg[2 * idx + 1]);
	};

	auto query = [&](int l, int r) {
		pii ret = { (int)1e9 + 1, 0 };
		for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret = oper(ret, seg[l++]);
			if (r & 1 ^ 1) ret = oper(ret, seg[r--]);
		}
		return ret;
	};

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		update(i, a);
	}

	while (m--) {
		int l, r; cin >> l >> r;
		auto [mm, MM] = query(l, r);
		cout << mm << ' ' << MM << '\n';
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
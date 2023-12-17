#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tii array<int, 3>
#define all(x) x.begin(), x.end()
#define INF (int)1e9

void solve() {
	int n, m; cin >> n >> m;
	int S = 1; S = bit_ceil(unsigned(n + m + 1));
	vector<int> pos(n + 1), seg(2 * S); iota(all(pos), 0);
	reverse(pos.begin() + 1, pos.end());
	
	auto update = [&](int idx, int val) {
		idx += S;
		seg[idx] = val;
		for (idx >>= 1; idx > 0; idx >>= 1)
			seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	};

	auto query = [&](int l, int r) {
		int ret = 0;
		for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret += seg[l++];
			if (r & 1 ^ 1) ret += seg[r--];
		}
		return ret;
	};

	for (int i = 1; i <= n; i++) update(i, 1);

	for (int i = 1; i <= m; i++) {
		int u; cin >> u;
		update(pos[u], 0);
		cout << query(pos[u] + 1, n + i) << ' ';
		pos[u] = n + i;
		update(pos[u], 1);
	}
	
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; cin >> t;
	while (t--) solve();
	

	return 0;
}
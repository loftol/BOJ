#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define ai4 array<int, 4> // [l, r, M, s]
#define all(v) v.begin(),v.end()

using namespace std;

int n, S = 1;
int MIN = -1e9;
vector<ai4> seg;

void init() {
	while (S < n) S <<= 1;
	seg = vector<ai4>(S * 2);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		seg[S + i] = { a, a, a, a };
	}

	int SS = S;
	while (SS /= 2) {
		for (int i = 0; i < SS; i++) {
			int j = i + SS;
			auto& [l, r, M, s] = seg[j];
			l = max(seg[2 * j][3] + seg[2 * j + 1][0], seg[2 * j][0]);
			r = max(seg[2 * j][1] + seg[2 * j + 1][3], seg[2 * j + 1][1]);
			M = max(max(l, r), seg[2 * j][1] + seg[2 * j + 1][0]);
			M = max(M, max(seg[2 * j][2], seg[2 * j + 1][2]));
			s = seg[2 * j][3] + seg[2 * j + 1][3];
		}
	}
}

ai4 query(int l, int r, int b, int e, int idx) {
	if (b >= l && e <= r) return seg[idx];
	if (l >= e || r <= b) return { MIN, MIN, MIN, 0 };
	int mid = (b + e) / 2;
	auto [l1, r1, M1, s1] = query(l, r, b, mid, idx * 2);
	auto [l2, r2, M2, s2] = query(l, r, mid, e, idx * 2 + 1);

	int lM = max(s1 + l2, l1);
	int rM = max(r1 + s2, r2);
	int M = max(r1 + l2, max(lM, rM));
	M = max(M, max(M1, M2));
	int s = s1 + s2;
	return { lM, rM, M, s };

}

void solve() {
	cin >> n;
	init();
	int q; cin >> q;
	while (q--) {
		int i, j; cin >> i >> j;
		cout << query(i - 1, j, 0, S, 1)[2] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	//cin >> tc;
	while (tc--) solve();
	return 0;
}
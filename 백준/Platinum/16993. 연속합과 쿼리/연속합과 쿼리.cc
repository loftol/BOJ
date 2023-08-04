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
ai4 e = { MIN, MIN, MIN, 0 };

ai4 oper(ai4& u, ai4& v) {
	auto [l1, r1, M1, s1] = u;
	auto [l2, r2, M2, s2] = v;
	int lM = max(s1 + l2, l1);
	int rM = max(r1 + s2, r2);
	int M = max(r1 + l2, max(lM, rM));
	M = max(M, max(M1, M2));
	int s = s1 + s2;
	return { lM, rM, M, s };
}

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
			seg[j] = oper(seg[2 * j], seg[2 * j + 1]);
		}
	}
}

ai4 query(int l, int r) {
	ai4 lret = e, rret = e;
	for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) lret = oper(lret, seg[l++]);
		if (r & 1 ^ 1) rret = oper(seg[r--], rret);
	}
	return oper(lret, rret);
}

void solve() {
	cin >> n;
	init();
	int q; cin >> q;
	while (q--) {
		int i, j; cin >> i >> j;
		cout << query(i - 1, j - 1)[2] << '\n';
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
#include <bits/stdc++.h>
#include<array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>

template<typename T>
struct Segtree {
	int S;
	vector<T> seg;
	T(*oper)(T, T);
	T e;

	Segtree() {
		S = 0;
		seg = vector<T>(2 * S);
		oper = [](T a, T b) {return a; };
		e = T();
	}

	Segtree(const vector<T>& arr, T _e = 0, T(*_oper)(T, T) = [](T a, T b) {return a + b; }) {
		int _n = arr.size();
		S = bit_ceil((unsigned int)_n);
		seg = vector<T>(2 * S, _e);
		oper = _oper;
		e = _e;

		for (int i = 0; i < _n; i++)
			seg[S + i] = arr[i];

		for (int SS = S / 2; SS > 0; SS /= 2)
			for (int i = SS; i < 2 * SS; i++)
				seg[i] = oper(seg[2 * i], seg[2 * i + 1]);
	}

	void update(int idx, T val) {
		idx += S;
		seg[idx] = val;
		for (idx >>= 1; idx > 0; idx >>= 1)
			seg[idx] = oper(seg[idx * 2], seg[idx * 2 + 1]);
	}

	T query(int l, int r) {
		T lret = e, rret = e;
		for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) lret = oper(lret, seg[l++]);
			if (r & 1 ^ 1) rret = oper(seg[r--], rret);
		}
		return oper(lret, rret);
	}
};

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<ll> arr(n); for (ll& i : arr) cin >> i;
	Segtree<ll> seg(arr);

	for (int i = 0; i < m + k; i++) {
		int q; cin >> q;
		ll x, y; cin >> x >> y;
		if (q == 1) seg.update(x - 1, y);
		else cout << seg.query(x - 1, y - 1) << '\n';
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
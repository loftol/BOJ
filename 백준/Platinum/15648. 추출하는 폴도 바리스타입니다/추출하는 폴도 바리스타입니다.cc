#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <bit>
#define ll long long
#define pii array<int, 3>
#define all(x) x.begin(), x.end()
using namespace std;

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
	int n, k, d; cin >> n >> k >> d;
	vector<int> arr(n);
	for (int& i : arr) cin >> i;
	Segtree<int> seg(vector<int>(500001), 0, [](int a, int b) {return max(a, b); });

	vector<int> modMax(k);

	int M = 0;

	for (int i = n - 1; i >= 0; i--) {
		int here = arr[i];
		int l = modMax[here % k] + 1;
		int b = max(0, here - d);
		int u = min(500000, here + d);
		l = max(l, seg.query(b, u) + 1);
		modMax[here % k] = max(l, modMax[here % k]);
		seg.update(here, l);
		M = max(l, M);
	}

	cout << M;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int tc = 1; 
	//cin >> tc;
	while(tc--)
		solve();
	return 0;
}

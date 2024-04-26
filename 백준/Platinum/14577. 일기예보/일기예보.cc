#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)998244353

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
		seg[idx] += val;
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

	int BSquery(int val) {
		int idx = 1;
		while (idx < S) {
			idx = 2*idx+1;
			if (seg[idx] < val) val -= seg[idx--];
		}
		return idx - S;
	}
};

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> arr(n + 1);
	vector<ll> xList = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		xList.push_back(arr[i]);
	}
	vector<ll> arr_copy = arr;

	vector<array<ll, 3>> queries(m);
	for (int i = 0; i < m; i++) {
		auto& [q, a, b] = queries[i];
		cin >> q;
		if (q == 1) {
			cin >> a >> b;
			arr[a] += b;
			xList.push_back(arr[a]);
		}
		else if (q == 2) {
			cin >> a >> b;
			arr[a] -= b;
			xList.push_back(arr[a]);
		}
		else if (q == 3) {
			cin >> a >> b;
			xList.push_back(a);
			xList.push_back(b);
		}
		else if (q == 4) {
			cin >> a;
		}
	}

	sort(all(xList));
	xList.erase(unique(all(xList)), xList.end());

	auto findIdx = [&](ll x) {
		return lower_bound(all(xList), x) - xList.begin();
	};

	arr = arr_copy;

	vector<int> acnt(xList.size());
	for (int i = 1; i <= n; i++) acnt[findIdx(arr[i])]++;
	
	Segtree<int> seg(acnt);
	
	for (auto [q, a, b] : queries) {
		if (q == 1) {
			acnt[findIdx(arr[a])]--;
			seg.update(findIdx(arr[a]), -1);
			arr[a] += b;
			acnt[findIdx(arr[a])]++;
			seg.update(findIdx(arr[a]), 1);
		}
		else if (q == 2) {
			acnt[findIdx(arr[a])]--;
			seg.update(findIdx(arr[a]), -1);
			arr[a] -= b;
			acnt[findIdx(arr[a])]++;
			seg.update(findIdx(arr[a]), 1);
		}
		else if (q == 3) {
			cout << seg.query(findIdx(a), findIdx(b)) << '\n';
		}
		else if (q == 4) {
			cout << xList[seg.BSquery(a)] << '\n';
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while (t--) solve();
}
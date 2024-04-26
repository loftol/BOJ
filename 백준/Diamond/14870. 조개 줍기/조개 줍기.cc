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

// 그냥 블랙박스로 써도 될 정도임
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
};

void solve() {
    // N개의 세그를 만든다.
	int n; cin >> n;
	ll total = 0;
	// one-base
	vector<vector<ll>> arr(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	// make table
	vector<vector<ll>> table(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			table[i][j] = max(table[i - 1][j], table[i][j - 1]) + arr[i][j];
			total += table[i][j];
		}
	}

	// table-differtialize
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 2; j--) {
			table[i][j] -= table[i][j - 1];
		}
	}
	vector<Segtree<ll>> segs(n + 1);
	segs[0] = Segtree<ll>(vector<ll>(n + 1));
	for (int i = 1; i <= n; i++) segs[i] = Segtree<ll>(table[i]);
    
	cout << total;

	for (int i = 0; i < n; i++) {
		cout << '\n';
		char c; int x, y; cin >> c >> x >> y;
		int v = 1;
		if (c == 'D') v = -1;
		// 투포인터를 사용해 첫번째 세그에서 값이 변해야하는 구간을 구한다.
		int l = y, r = y + 1;
		for (int u = x; u <= n; u++) {
			if (u != x) {
				while (l < r) {
					ll q1 = segs[u].query(0, l - 1);
					ll q2 = segs[u - 1].query(0, l);
					if ((c == 'U' && q1 >= q2) || (c == 'D' && q1 > q2)) l++;
					else break;
				}
			}
			if (l < r) {
				while (r <= n) {
					ll q1 = segs[u].query(0, r - 1) + v;
					ll q2 = segs[u - 1].query(0, r);
					if ((c == 'U' && q1 > q2) || (c == 'D' && q1 >= q2)) r++;
					else break;
				}
				segs[u].update(l, v);
				if (r <= n) segs[u].update(r, -v);
				total += (r - l) * v;
				//cout << u << ' ' << l << ' ' << r << '\n';
			}
			else break;
		}
		/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << segs[i].seg[j+segs[i].S] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		*/
		cout << total;
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
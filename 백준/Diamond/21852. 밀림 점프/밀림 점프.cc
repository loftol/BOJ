#include "jumps.h"
#include <bits/stdc++.h>
#include <array>

#define pii array<int, 2>
#define all(x) x.begin(), x.end()
#define INF (int)1e9 + 1
#define fii array<int, 5>
using namespace std;

int top = -1;
vector<pii> bnd; // [left, right, lbnd, rbnd]
vector<vector<fii>> dtable;
vector<int> depth;
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

	T query(int l, int r) {
		T lret = e, rret = e;
		for (l += S, r += S; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) lret = oper(lret, seg[l++]);
			if (r & 1 ^ 1) rret = oper(seg[r--], rret);
		}
		return oper(lret, rret);
	}
};

Segtree<pii> seg;

void init(int n, vector<int> H) {
	int S = bit_ceil((unsigned) n);
	bnd = vector<pii>(n);
	vector<pii> h(n);
	depth = vector<int>(n);
	dtable = vector<vector<fii>>(30, vector<fii>(n));

	for (int i = 0; i < n; i++) {
		h[i] = { H[i], i };
	}

	seg = Segtree<pii>(h, array{ 0, -1 }, [](pii a, pii b) {return max(a, b); });

	function<int(int, int, int)> dnc = [&](int l, int r, int dep) {
		auto [mval, pivot] = seg.query(l, r);
		int left = -1, right = -1;
		if (pivot != l) {
			left = dnc(l, pivot - 1, dep + 1);
			dtable[0][left][0] = pivot;
			dtable[0][left][4] = -1;
		}
		if (pivot != r) {
			right = dnc(pivot + 1, r, dep + 1);
			dtable[0][right][0] = pivot;
			dtable[0][right][4] = 1;
		}
		
		dtable[0][pivot][0] = pivot;
		dtable[0][pivot] = { pivot, 1, 1, 0, 0 };
		bnd[pivot] = { l, r };
		depth[pivot] = dep;
		return pivot;
	};
	top = dnc(0, n - 1, 1);
	dtable[0][top][1] = 0;
	dtable[0][top][2] = 0;
	for (int i = 1; i < 30; i++) {
		for (int j = 0; j < n; j++) {
			auto [ppar, pcnt, pre, pturn, pdir] = dtable[i - 1][j];
			auto [npar, ncnt, nre, nturn, ndir] = dtable[i - 1][ppar];
			int par = npar;
			int cnt = pcnt + ncnt;
			int sub = 0;
			if (!nturn) sub = 1;
			int re = pre + nre;
			nturn = nturn || (pdir * ndir == -1);
			int turn = pturn || nturn;
			if (nturn) {
				re = nre - sub;
				cnt -= pre;
			}
			dtable[i][j] = { par, cnt, re, turn, ndir };
		}
	}
}

int minimum_jumps(int A, int B, int C, int D) {
	int here = C;
	for (int exp = 29; exp >= 0; exp--) {
		int par = dtable[exp][here][0];
		if (bnd[par][1] >= A && bnd[par][0] <= B) continue;
		here = par;
	}
	if (!(bnd[here][1] >= A) || !(bnd[here][0] <= B))
		here = dtable[0][here][0];
	if (here < C || here > D) {
		for (int exp = 29; exp >= 0; exp--) {
			int par = dtable[exp][here][0];
			if (C <= par && par <= D) continue;
			here = par;
		}
		if (here < C || here > D)
			here = dtable[0][here][0];
	}
	int X = here;

 	if (X < C || X > D) return -1;
	int l = max(A, bnd[here][0]);
	int r = min(B, bnd[here][1]);
	auto[mval, Y] = seg.query(l, r);
	int dd = depth[Y] - depth[X];
	here = Y;
	int cnt = 0, re = 0, dir = 0;
	for (int exp = 29; exp >= 0; exp--) {
		if (dd & (1 << exp)) {
			dd -= (1 << exp);
			auto [npar, ncnt, nre, nturn, ndir] = dtable[exp][here];
			cnt += ncnt;
			here = npar;
			int sub = 0;
			if (!nturn) sub = 1;
			nturn = nturn || (dir * ndir == -1);
			dir = ndir;
			if (nturn) {
				cnt -= re;
				re = nre - sub;
			}
			else {
				re += nre;
			}
		}
	}
	return cnt;
}

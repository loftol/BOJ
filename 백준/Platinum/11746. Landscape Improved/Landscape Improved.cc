#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define tll array<long long, 3>
#define pll array<long long, 2>

int MOD = 998244353;

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

	int BSLquery(int idx, int val) {
		idx += S;
		idx /= 2;
		while (idx > 1 && seg[2 * idx] < val) {
			idx /= 2;
		}
		if (seg[2 * idx] < val) {
			return -1;
		}
		idx *= 2;
		while (idx < S) {
			idx = 2 * idx + 1;
			if (seg[idx] < val) idx--;
		}
		return idx - S;
	}

	int BSRquery(int idx, int val) {
		idx += S;
		idx /= 2;
		while (idx > 1 && seg[2 * idx + 1] < val) {
			idx /= 2;
		}
		if (seg[2 * idx + 1] < val) {
			return -1;
		}
		idx = 2 * idx + 1;
		while (idx < S) {
			idx *= 2;
			if (seg[idx] < val) idx++;
		}
		return idx - S;
	}
};

void solve() {
    int n; ll k; cin >> n >> k;

    vector<int> arr(n); for (int& i : arr) cin >> i;

    vector<int> right(n), left(n);
    for (int i = 0; i < n; i++) {
        left[i] = right[i] = arr[i];
        right[i] += i;
        left[i] += (n - 1 - i);
    }

	vector<ll> rsum(n + 1), lsum(n + 1);
	for (int i = 0; i < n; i++) {
		rsum[i + 1] = right[i] + rsum[i];
		lsum[i + 1] = left[i] + lsum[i];
	}

	Segtree<int> rseg(right, 0, [](int a, int b) {return max(a, b); });
	Segtree<int> lseg(left, 0, [](int a, int b) {return max(a, b); });

    auto pmsearch = [&](int x) {
		for (int i = 0; i < n; i++) {
			if (arr[i] >= x) 
				return true;
			ll r = rseg.BSRquery(i, i + x);
			ll l = lseg.BSLquery(i, (n - 1) - i + x);
			if (r == -1 || l == -1) continue;
			ll y = (r - i) * (i + x) - (rsum[r] - rsum[i]);
			y += (i - l - 1) * ((n - 1) - i + x) - (lsum[i] - lsum[l + 1]);
			if (y <= k) {
				return true;
			}
		}
		return false;
    };

	ll l = 0, r = 2e9 + 1;
	while (l + 1 < r) {
		ll mid = (l + r) / 2;
		if (pmsearch(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	cout << l << '\n';

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
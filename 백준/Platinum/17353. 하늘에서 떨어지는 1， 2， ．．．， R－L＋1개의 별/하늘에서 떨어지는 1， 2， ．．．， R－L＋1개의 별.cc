#include<iostream>
#include<vector>
#define ll long long
#define vi vector<ll>

using namespace std;

vi seg, lazy;

int N, Q, S = 1;

void makeSeg(int n, int s, int e) {
	if (e - s == 1) return;
	int mid = (e + s) / 2;
	makeSeg(2 * n, s, mid);
	makeSeg(2 * n + 1, mid, e);
	seg[n] = seg[2 * n] + seg[2 * n + 1];
}

void updateLazy(int n, int s, int e) {
	if (!lazy[n]) return;
	seg[n] += lazy[n] * (e - s);
	if (e - s > 1) {
		lazy[2 * n] += lazy[n];
		lazy[2 * n + 1] += lazy[n];
	}
	lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, ll val) {
	updateLazy(n, s, e);
	if (l >= e || r <= s) return;
	if (l <= s && e <= r) {
		seg[n] += (e - s) * val;
		if (e - s > 1) {
			lazy[n * 2] += val;
			lazy[n * 2 + 1] += val;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(2 * n, s, mid, l, r, val);
	update(2 * n + 1, mid, e, l, r, val);
	seg[n] = seg[2 * n] + seg[2 * n + 1];
}

ll getSum(int n, int s, int e, int l, int r) {
	updateLazy(n, s, e);
	if (l >= e || r <= s) return 0;
	if (l <= s && e <= r) return seg[n];
	int mid = (s + e) / 2;
	return getSum(2 * n, s, mid, l, r) + getSum(2 * n + 1, mid, e, l, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	while (S < N) S <<= 1;

	seg = vi(2 * S);
	lazy = vi(2 * S);

	int prev = 0;
	for (int i = 0; i < N; i++) {
		int inp;
		cin >> inp;
		seg[S + i] = inp - prev;
		prev = inp;
	}

	makeSeg(1, 0, S);

	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			update(1, 0, S, b - 1, c, 1);
			if (c != N) update(1, 0, S, c, c + 1, -1 * (c - b + 1));
		}
		else {
			int b;
			cin >> b;
			cout << getSum(1, 0, S, 0, b) << '\n';
		}
	}

	return 0;
}
#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

int n = 1000001, S = 1;

vector<int> seg;
vector<vector<int>> adj;
vector<pii> vst;
void init() {
	while (S < n + 1) S <<= 1;
	seg = vector<int>(S * 2);
	for (int i = 0; i < n; i++) {
		cin >> seg[S + i];
	}

	for (int SS = S / 2; SS; SS /= 2) {
		for (int i = 0; i < SS; i++) {
			int j = SS + i;
			seg[j] = min(seg[2 * j], seg[2 * j + 1]);
		}
	}
}

int BSquery(int i, int j) {
	int here = i + S;
	int hi = S;
	while (here >>= 1) {
		if (seg[here] < j) {
			if (seg[here * 2] < j)
				hi = here * 2;
			else
				hi = here * 2 + 1;
			while (hi < S) {
				if (seg[hi * 2] < j) hi *= 2;
				else hi = hi * 2 + 1;
			}
			return hi -= S;
		}
	}
	return n + 1;
}

void update(int idx, int val) {
	idx += S;
	seg[idx] += val;
	while (idx /= 2)
		seg[idx] = min(seg[idx * 2],seg[idx * 2 + 1]);
}

void solve() {
	cin >> n;

	int mm = 1000001;

	init();
	ll sum = 0;
	for (int i = 0; i <= n; i++) {
		int j = S + i;
		sum += (ll)(mm - min(mm, seg[j])) * i;
		mm = min(mm, seg[j]);
	}

	cout << sum << '\n';

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			int val = seg[b + S];
			val++;
			update(b, 1);
			int r = BSquery(0, val);
			if (r > b) {
				sum += r - b;
			}
		}
		else {
			int val = seg[b + S];
			int r = BSquery(0, val);
			if (r > b) {
				sum -= r - b;
			}
			update(b, -1);
		}
		cout << sum << '\n';
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
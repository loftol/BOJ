#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

int n, S = 1;

vector<int> seg;
vector<vector<int>> adj;
vector<pii> vst;
void init() {
	while (S < n) S <<= 1;
	seg = vector<int>(S * 2);
}

int query(int l, int r, int b, int e, int idx) {
	if (b >= l && e <= r) return seg[idx];
	if (b >= r || e <= l) return 0;
	int mid = (b + e) / 2;
	return query(l, r, b, mid, idx * 2) + query(l, r, mid, e, idx * 2 + 1);
}

void update(int idx, int val) {
	idx += S;
	seg[idx] += val;
	while (idx /= 2)
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int u = 0;
void dfs(int here) {
	vst[here][0] = u++;
	for (int next : adj[here]) dfs(next);
	vst[here][1] = u++;
}

void solve() {
	int q;
	cin >> n >> q;
	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i <= n; i++) {
		int j; cin >> j;
		if (j != -1) {
			adj[j].push_back(i);
		}
	}

	vst = vector<pii>(n + 1, { -1, -1 });
	dfs(1);
	n *= 2;

	init();
	while (q--) {
		int x, node; cin >> x >> node;
		auto [i, j] = vst[node];
		if (x == 1) {
			int val; cin >> val;
			update(i, val);
		}
		else if (x == 2) {
			cout << query(i, j + 1, 0, S ,1) << '\n';
		}
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
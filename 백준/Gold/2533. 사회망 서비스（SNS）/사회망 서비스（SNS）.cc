#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>
#define all(x) x.begin(), x.end()

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);

	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vst(n + 1), color(n + 1, 1);
	int ans = 0;
	function<int(int)> dfs = [&](int here) {
		vst[here] = 1;
		int& c = color[here];
		for (int next : adj[here]) {
			if (!vst[next]) c &= dfs(next);
		}
		c ^= 1;
		ans += c;
		return c;
	};

	dfs(1);

	cout << ans;
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
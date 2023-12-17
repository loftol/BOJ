#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tii array<int, 3>
#define all(x) x.begin(), x.end()
#define INF (int)1e9
void solve() {
	int n; cin >> n;
	vector<vector<pii>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	vector<vector<tii>> dtable(30, vector<tii>(n + 1));
	vector<int> depth(n + 1);

	function<void(int, int)> make_sparse_table = [&](int here, int par) {
		depth[here] = depth[par] + 1;
		for (auto [next, ndst] : adj[here]) {
			if (next != par) {
				dtable[0][next] = { here, ndst, ndst };
				make_sparse_table(next, here);
			}
		}
	};

	make_sparse_table(1, 0);

	dtable[0][1] = { 1, INF, 0 };
	for (int i = 1; i < 30; i++) {
		for (int j = 1; j <= n; j++) {
			int par = dtable[i - 1][dtable[i - 1][j][0]][0];
			int minDst = min(dtable[i - 1][dtable[i - 1][j][0]][1], dtable[i - 1][j][1]);
			int maxDst = max(dtable[i - 1][dtable[i - 1][j][0]][2], dtable[i - 1][j][2]);
			dtable[i][j] = { par, minDst, maxDst };
		}
	}

	

	function<pii(int, int)> lca = [&](int a, int b) {
		if (depth[a] > depth[b]) swap(a, b);
		int minRet = 1e9 + 1, maxRet = 0;
		int dd = depth[b] - depth[a];
		int exp = 0;
		while (dd) {
			if (dd & 1) {
				minRet = min(minRet, dtable[exp][b][1]);
				maxRet = max(maxRet, dtable[exp][b][2]);
				b = dtable[exp][b][0];
			}
			exp++;
			dd >>= 1;
		}

		for (exp = 29; exp >= 0; exp--) {
			if (dtable[exp][b][0] != dtable[exp][a][0]) {
				minRet = min({ minRet, dtable[exp][b][1], dtable[exp][a][1] });
				maxRet = max({ maxRet, dtable[exp][b][2], dtable[exp][a][2] });
				b = dtable[exp][b][0], a = dtable[exp][a][0];
			}
		}

		exp = 0;

		if (a != b) {
			minRet = min({ minRet, dtable[exp][b][1], dtable[exp][a][1] });
			maxRet = max({ maxRet, dtable[exp][b][2], dtable[exp][a][2] });
		}

		return array{ minRet, maxRet };
	};

	int k; cin >> k;

	while (k--) {
		int a, b; cin >> a >> b;
		auto [minRet, maxRet] = lca(a, b);
		cout << minRet << ' ' << maxRet << '\n';
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
#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

deque<vector<int>> dq;
vector<int> dst;
vector<vector<pii>> adj;

void solve() {
	dq = deque<vector<int>>(11);
	int n, m, k; cin >> n >> m >> k;
	adj = vector<vector<pii>>(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;

		adj[u].push_back({ v, w });
	}
	dst = vector<int>(n + 1, -1);
	int d = 0;
	int emptyCnt = 0;
	dq[0].push_back(k);
	while (emptyCnt < 10) {
		if (dq[0].size() == 0)
			emptyCnt++;
		else emptyCnt = 0;
		while (dq[0].size()) {
			int here = dq[0].back();
			dq[0].pop_back();
			if (dst[here] != -1) continue;
			dst[here] = d;
			for (auto [next, w] : adj[here]) {
				if (dst[next] != -1) continue;
				dq[w].push_back(next);
			}
		}
		dq.pop_front();
		dq.push_back(vector<int>());
		d++;
	}

	for (int i = 1; i <= n; i++) {
		if (dst[i] != -1) cout << dst[i] << '\n';
		else cout << "INF" << '\n';
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
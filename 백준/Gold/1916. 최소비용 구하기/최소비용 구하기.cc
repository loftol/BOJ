#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define pii array<int, 2>
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n + 1);
	vector<pii> index(n + 1, {-1, -1});
	vector<int> dst(n + 1, 1e9);
	vector<vector<int>> dial(100001);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	int s, t; cin >> s >> t;

	dial[0].push_back(s);
	dst[0] = 0;

	int cnt = 1;
	int hdst = 0;
	while (cnt) {
		int mhdst = hdst % 100001;
		bool visted = false;
		while (dial[mhdst].size()) {
			int here = dial[mhdst].back();
			cnt--;
			visted = true;
			dial[mhdst].pop_back();
			for (auto [next, ndst] : adj[here]) {
				if (hdst + ndst >= dst[next]) continue;
				ndst += hdst;
				int mndst = ndst % 100001;
				if (index[next][0] != -1) {
					auto [u, v] = index[next];
					int target = dial[u].back();
					index[target][1] = v;
					swap(dial[u].back(), dial[u][v]);
					dial[u].pop_back();
				}
				else cnt++;
				index[next] = { mndst, (int)dial[mndst].size() };
				dst[next] = ndst;
				dial[mndst].push_back(next);
			}
		}
		hdst++;
	}

	cout << dst[t];

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	for (int t = 1; t <= tc; t++) solve();
}

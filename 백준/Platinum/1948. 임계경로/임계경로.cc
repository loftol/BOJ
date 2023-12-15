#include <bits/stdc++.h>
#include<array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>

void solve() {
	int n, m; cin >> n >> m;

	vector<vector<pii>> adj(n + 1);
	vector<int> ind(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		ind[v]++;
	}

	vector<int> table(n + 1);
	queue<int> q;
	int s, t; cin >> s >> t;
	q.push(s);
	vector<vector<int>> rev_adj(n + 1);
	while (q.size()) {
		int here = q.front();
		q.pop();
		for (auto [next, w] : adj[here]){
			if (table[next] < table[here] + w) {
				table[next] = table[here] + w;
				rev_adj[next] = { here };
			}
			else if (table[next] == table[here] + w) {
				rev_adj[next].push_back(here);
			}
			ind[next]--;
			if (!ind[next]) q.push(next);
		}
	}

	cout << table[t] << '\n';
	vector<int> vst(n + 1);
	int ans = 0;
	function<void(int)> dfs = [&](int here) {
		vst[here] = 1;
		ans += rev_adj[here].size();
		for (int next : rev_adj[here]) {
			if (!vst[next])
				dfs(next);
		}
	};
	dfs(t);
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
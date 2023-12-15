#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>
#define all(x) x.begin(), x.end()

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> sccID(n + 1), vst(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	int vstCnt = 1, sccCnt = 1;
	vector<int> stk;
	vector<vector<int>> SCC;
	function<pii(int)> dfs = [&](int here) {
		vst[here] = vstCnt++;
		stk.push_back(here);
		pii ret = { vst[here], here };
		for (int next : adj[here]) {
			if (!vst[next]) {
				ret = min(dfs(next), ret);
			}
			else if (!sccID[next]) {
				ret = min(array{ vst[next], next }, ret);
			}
		}
		if (ret == array{ vst[here], here }) {
			vector<int> scc;
			while (stk.back() != here) {
				sccID[stk.back()] = sccCnt;
				scc.push_back(stk.back());
				stk.pop_back();
			}
			sccID[stk.back()] = sccCnt++;
			scc.push_back(stk.back());
			stk.pop_back();
			sort(all(scc));
			SCC.push_back(scc);
		}
		return ret;
	};
	for (int i = 1; i <= n; i++) {
		if (!vst[i]) dfs(i);
	}
	sort(all(SCC));
	cout << SCC.size() << '\n';
	for (auto scc : SCC) {
		for (int i : scc) cout << i << ' ';
		cout << "-1\n";
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
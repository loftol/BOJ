#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tii array<int, 3>
#define all(x) x.begin(), x.end()
#define INF (int)1e9
void solve(int n, int m) {
	vector<vector<int>> adj(2 * n + 2);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u = abs(u) * 2 + (u > 0 ? 0 : 1);
		v = abs(v) * 2 + (v > 0 ? 0 : 1);
		adj[u ^ 1].push_back(v);
		adj[v ^ 1].push_back(u);
	}
	adj[3].push_back(2);
	int sccCnt = 1, vstCnt = 1;
	vector<int> sccID(2 * n + 2), vst(2 * n + 2), stk;
	function<int(int)> make_scc = [&](int here) {
		if (vst[here]) return vst[here];
		vst[here] = vstCnt++; stk.push_back(here);
		int ret = vst[here];
		for (int next : adj[here]) if (!sccID[next])ret = min(make_scc(next), ret);
		if (ret == vst[here]) {
			while (stk.size() && vst[stk.back()] >= vst[here]) {
				sccID[stk.back()] = sccCnt;
				stk.pop_back();
			}
			sccCnt++;
		}
		return ret;
	};

	for (int i = 1; i <= 2 * n + 1; i++) if (!vst[i]) make_scc(i);


	bool pos = true;
	for (int i = 1; i <= n; i++) {
		if (sccID[2 * i] == sccID[2 * i + 1]) pos = false;
	}
	if (pos) cout << "yes\n";
	else cout << "no\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; //cin >> t;
	int n, m;
	while (cin >> n >> m) {
		solve(n, m);
	}

	return 0;
}
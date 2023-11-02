#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define tii array<ll, 3>
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)

int n, m;
vector<vector<int>> adj, rev_adj;
vector<int> ind, vst;
vector<int> cycled;
bool cycle = false;
void dfs(int here) { // 사이클 판별, 유효 정점 확인, ind 초기화
	if (vst[here] && !ind[here]) cycled[here] = true;
	if (cycled[here]) return;
	vst[here] = 1;
	for (int next : adj[here]) {
		if (!ind[next]) dfs(next);
		ind[next]++;
	}
}

void dfs2(int here) { // 사이클 있는 지점에 역간선으로 도달 가능한지만 확인
	vst[here] = 2;
	if (cycled[here]) cycle = true;
	for (int next : rev_adj[here]) {
		if (!(vst[next] == 2)) dfs2(next);
	}
}

void solve() {
	cin >> n >> m;
	rev_adj = adj = vector<vector<int>>(n + 1);
	ind = vst = cycled = vector<int>(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	}
	
	dfs(1);
	dfs2(2);
	if (cycle) {
		cout << "inf";
		return;
	}

	queue<int> q;
	q.push(1);
	vector<array<int, 2>> table(n + 1);
	table[1] = { 1 , 0 };
	while (q.size()) {
		int here = q.front();
		q.pop();
		for (int next : adj[here]) {
			if (!--ind[next]) q.push(next);
			table[next][0] += table[here][0];
			table[next][1] |= table[here][1];
			if (table[next][0] >= (int)1e9) table[next][1] = 1;
			table[next][0] %= (int)1e9;
		}
	}
	if (table[2][1]) {
		cout.width(9);
		cout.fill('0');
	}
	cout << table[2][0];

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	for (int t = 1; t <= tc; t++) solve();
}

#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define tii array<ll, 3>
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)

vector<int> par;
vector<tii> points, ori_points;
vector<array<int, 2>> tree;
vector<int> ans;
int cnt = 1;
void recur(int here) {
	if (tree[here][0]) recur(tree[here][0]);
	ans[here] = cnt++;
	if (tree[here][1]) recur(tree[here][1]);
}

void solve() {
	int n; cin >> n;
	ans = vector<int>(n + 1);
	vector<vector<int>> adj(1);
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		vector<int> arr = { 0 };
		for (char c : str) {
			arr.push_back(c - '0');
		}
		adj.push_back(arr);
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] |= adj[i][k] & adj[k][j];

	tree = vector<array<int, 2>>(n + 1, { 0, 0 });

	for (int i = 2; i <= n; i++) {
		int here = 1;
		while (true) {
			int dir = 0;
			if (adj[here][i] && adj[i][here]) {
				cout << -1;
				return;
			}
			if (!adj[i][here]) dir = 1;
			if (!tree[here][dir]) {
				tree[here][dir] = i;
				break;
			}
			here = tree[here][dir];
		}
	}

	recur(1);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	for (int t = 1; t <= tc; t++) solve();
}

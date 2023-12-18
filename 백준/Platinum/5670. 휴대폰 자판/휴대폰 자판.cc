#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tii array<int, 3>
#define pll array<ll, 2>
#define all(x) x.begin(), x.end()
#define INF (int)1e9

void solve(int n) {
	vector<unordered_map<char, int>> adj(1);
	vector<int> cnt(1);
	
	int nodeCnt = 1;

	vector<string> strs;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		strs.push_back(str);
		int here = 0;
		for (char c : str) {
			if (adj[here].find(c) == adj[here].end()) {
				adj.push_back(unordered_map<char, int>());
				adj[here][c] = nodeCnt++;
				cnt.push_back(0);
			}
			here = adj[here][c];
		}
		cnt[here]++;
	}

	int ans = 0;
	for (string str : strs) {
		int here = 0;
		for (char c : str) {
			if (here == 0 || adj[here].size() != 1 || cnt[here]) ans++;
			here = adj[here][c];
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << (double)ans/n << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; //cin >> t;
	int n;
	while (cin >> n) {
		solve(n);
	}

	return 0;
}
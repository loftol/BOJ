#include <bits/stdc++.h>
#include <array>
#include <random>

#define ll long long int
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

int n, MOD = 1e9 + 7;
ll base = 27, base_p = 1;
int ans = 0;
ll target_hash;
string p;
vector<vector<pair<int, char>>> adj;
vector<vector<pair<int, char>>> fastPar;

void dfs(int here, ll hash, int depth) {
	if (hash == target_hash) ans++;
	int P = p.size() - 1;
	int exp = 0;
	int par = here;
	while (P) {
		if (P & 1) par = fastPar[exp][par].first;
		exp++;
		P >>= 1;
	}
	hash *= base;
	pair<int, char> parchar = fastPar[0][par];
	if (depth >= p.size()) {
		hash += parchar.second * (MOD - base_p);
	}
	for (auto [next, c] : adj[here]) {
		dfs(next, (hash + c) % MOD, depth + 1);
	}
}

void solve() {
	cin >> n;

	adj = vector<vector<pair<int, char>>>(n + 1);
	fastPar = vector<vector<pair<int, char>>>(20, vector<pair<int, char>>(n + 1));
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		char c; cin >> c;
		adj[u].push_back({ v, c });
		fastPar[0][v] = { u, c };
	}
	
	for (int lvl = 1; lvl < 20; lvl++) {
		for (int i = 1; i <= n; i++) {
			fastPar[lvl][i] = fastPar[lvl - 1][fastPar[lvl - 1][i].first];
		}
	}

	cin >> p;

	for (int i = 0; i < p.size(); i++) {
		target_hash = (target_hash * base + p[i]) % MOD;
		base_p = (base_p * base) % MOD;
	}

	for (int i = 1; i <= n; i++) {
		if (fastPar[0][i].first == 0) {
			dfs(i, 0, 0);
		}
	}

	cout << ans;

	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1; //cin >> tc;
	while (tc--) solve();


	return 0;
}
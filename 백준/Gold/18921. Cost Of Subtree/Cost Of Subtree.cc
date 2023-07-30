#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 3>
#define all(v) v.begin(),v.end()

using namespace std;

vector<int> par, cnt;
ll M = 0;


int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

int uni(int a, int b) {
	if ((a = find(a)) != (b = find(b))) {
		cnt[a] += cnt[b];
		return par[b] = a;
	}
	return false;
}

void solve() {
	int n; cin >> n;
	vector<pii> edges(n - 1);
	cnt = vector<int>(n + 1, 1);
	par = vector<int>(n + 1);
	iota(all(par), 0);
	for (auto& [v, a, b] : edges) cin >> a >> b >> v;

	sort(all(edges), greater<>());

	

	for (auto [v, a, b] : edges) {
		if (a = uni(a, b)) {
			M = max((ll)(cnt[a] - 1) * v, M);
		}
	}

	cout << M << '\n';
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
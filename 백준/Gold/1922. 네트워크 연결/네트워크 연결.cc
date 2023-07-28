#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 3>
#define all(v) v.begin(),v.end()

using namespace std;

vector<int> par;
vector<pii> edge;

int find(int a) {
	if (par[a] != a) return par[a] = find(par[a]);
	return a;
}

bool uni(int a, int b) {
	if ((a = find(a)) != (b = find(b))) {
		par[b] = a;
		return true;
	}
	return false;
}

void solve()
{
	int n, m; cin >> n >> m;
	edge = vector<pii>(m);
	par = vector<int>(n + 1);
	iota(all(par), 0);

	for (auto& [w, u, v] : edge) cin >> u >> v >> w;

	sort(all(edge));

	ll sum = 0;
	for (auto [w, u, v] : edge) {
		if (uni(u, v)) {
			sum += w;
		}
	}

	cout << sum << '\n';
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
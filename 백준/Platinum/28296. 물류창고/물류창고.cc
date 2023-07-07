#include<bits/stdc++.h>
#include<array>

using namespace std;

#define ll long long
#define tii array<ll, 3>
#define MAX 500000
#define all(x) x.begin(), x.end()

vector<map<int, ll>> cnts;// [node][color] => cnt
vector<int> par;// 유파용 par 배열

int find(int a) {
	if (par[a] != a) return par[a] = find(par[a]);
	return a;
}

bool uni(int a, int b) {
	if (find(a) != find(b)) {
		par[par[b]] = par[a];
		return true;
	}
	return false;
}

void solve() {
	int n, k, m;
	cin >> n >> k >> m;

	vector<int> C(n + 1);
	par = vector<int>(n + 1);
	iota(all(par), 0);
	cnts = vector<map<int, ll>>(n + 1);

	for (int i = 1; i <= n; i++) {
		int color;
		cin >> color;
		cnts[i][color] = 1;
	}

	vector<tii> edges(m);
	for (auto& [u, v, w] : edges)
		cin >> u >> v >> w;

	sort(all(edges), [](tii a, tii b) {
		if (a[2] == b[2]) return a[1] < b[1];
	return a[2] > b[2];
		});

	vector<ll> limitSum(k + 1);

	for (auto [u, v, w] : edges) {
		int pu = find(u), pv = find(v);
		if (cnts[pu].size() < cnts[pv].size()) swap(pu, pv);
		if (uni(pu, pv)) {
			for (auto [color, cnt] : cnts[pv]) {
				limitSum[color] += cnts[pu][color] * cnts[pv][color] * w;
				cnts[pu][color] += cnts[pv][color];
			}
		}
	}

	for (int color = 1; color <= k; color++) {
		cout << limitSum[color] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();


	return 0;
}
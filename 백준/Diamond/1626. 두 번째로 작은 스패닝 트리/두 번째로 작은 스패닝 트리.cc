#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cassert>
using namespace std;

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define mat vector<vi>
#define mt tuple<int,int,int>
#define vt vector<mt>
#define ll long long

int n, e;

vi dep;
vector<vt> adj; // {weight, from, to}
priority_queue<mt, vt, greater<>> pq; // {weight, from, to}
mat par, Msp, SMsp;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> e;

	par = Msp = SMsp = mat(20, vi(n + 1, -1));
	adj = vector<vt>(n + 1);
	dep = vi(n + 1);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ w, u, v });
		adj[v].push_back({ w, v, u });
	}

	pq.push({ -1, 1, 1 });

	int cnt = 0;
	int subMin = 100'001;
	int mstCost = 0;
	while (pq.size()) {
		auto [w, prev, here] = pq.top();
		pq.pop();

		// 이미 방문한 노드일때 lca
		if (dep[here]) {
			if (dep[prev] > dep[here]) swap(prev, here);
			int dh = dep[here] - dep[prev];
			int MW = -1;

			int lvl = 0;
			while (dh) {
				if (dh & 1) {
					if (Msp[lvl][here] < w)
						MW = max(Msp[lvl][here], MW);
					else
						MW = max(SMsp[lvl][here], MW);
					here = par[lvl][here];
				}
				dh >>= 1;
				lvl++;
			}

			lvl = 19;
			while (here != prev) {
				if (par[lvl][here] != par[lvl][prev] || (lvl == 0 && here != prev)) {
					assert(Msp[lvl][here] <= w);
					if (Msp[lvl][here] < w)
						MW = max(Msp[lvl][here], MW);
					else
						MW = max(SMsp[lvl][here], MW);
					if (Msp[lvl][prev] < w)
						MW = max(Msp[lvl][prev], MW);
					else
						MW = max(SMsp[lvl][prev], MW);
					here = par[lvl][here];
					prev = par[lvl][prev];
				}
				else lvl--;
			}

			if (MW != -1)
				subMin = min(w - MW, subMin);

			continue;
		}

		// 처음 방문한 노드일때 sparse table 초기화, pq에 간선추가
		cnt++;
		dep[here] = dep[prev] + 1;
		mstCost += w;
		par[0][here] = prev;
		Msp[0][here] = w;

		for (int lvl = 1; lvl < 20; lvl++) {
			int mid = par[lvl - 1][here];
			par[lvl][here] = par[lvl - 1][mid];

			vi arr = { Msp[lvl - 1][here], Msp[lvl - 1][mid], SMsp[lvl - 1][here], SMsp[lvl - 1][mid] };
			sort(all(arr));
			arr.erase(unique(all(arr)), arr.end());

			Msp[lvl][here] = arr.back();
			arr.pop_back();
			if (arr.size()) {
				SMsp[lvl][here] = arr.back();
			}
		}

		for (auto [nw, ignore, next] : adj[here]) {
			if (next != prev) {
				pq.push({ nw, here, next });
			}
		}


	}

	if (subMin == 0 || cnt < n || subMin == 100'001)
		cout << -1;
	else
		cout << mstCost + subMin + 1;


	return 0;
}
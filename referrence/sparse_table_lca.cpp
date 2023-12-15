#include <vector>
#include <array> // 이건 bits/stdc++.h 해도 넣어야 한다.

using namespace std;

#define pii array<int, 2>

int n; cin >> n;
vector<vector<pii>> adj(n + 1);
for (int i = 1; i < n; i++) {
	int u, v, w; cin >> u >> v >> w;
	adj[u].push_back({ v, w });
	adj[v].push_back({ u, w });
}

// 아래에서 30이랑 이것저것 잘 조절해서 쓸 것
vector<vector<pii>> dtable(30, vector<pii>(n + 1));
vector<int> depth(n + 1);

// sparse table의 base part 초기화 부분
function<void(int, int)> make_sparse_table = [&](int here, int par) {
	depth[here] = depth[par] + 1;
	for (auto [next, ndst] : adj[here]) {
		if (next != par) {
			dtable[0][next] = { here, ndst };
			make_sparse_table(next, here);
		}
	}
};

make_sparse_table(1, 0);

// sparse table의 exponential part 초기화 부분
dtable[0][1] = { 1, 0 };
for (int i = 1; i < 30; i++) {
	for (int j = 1; j <= n; j++) {
		// 요소에 맞춰 작성해주면 됨
		int par = dtable[i - 1][dtable[i - 1][j][0]][0];
		int dst = dtable[i - 1][dtable[i - 1][j][0]][1] + dtable[i - 1][j][1];
		dtable[i][j] = { par, dst };
	}
}

//lca 겸 a, b 사이의 무언가 계산해주는 파트 (exp 시작 및 끝 주의해서 사용할 것)
int a, b; cin >> a >> b;
if (depth[a] > depth[b]) swap(a, b);
ll ret = 0;
int dd = depth[b] - depth[a];
int exp = 0;
while (dd) {
	if (dd & 1) {
		ret += dtable[exp][b][1];
		b = dtable[exp][b][0];
	}
	exp++;
	dd >>= 1;
}
for (exp = 29; exp >= 0; exp--) {
	if (dtable[exp][b][0] != dtable[exp][a][0]) {
		ret += dtable[exp][b][1] + dtable[exp][a][1];
		b = dtable[exp][b][0], a = dtable[exp][a][0];
	}
}
exp = 0;
if (a != b) {
	ret += dtable[exp][b][1] + dtable[exp][a][1];
	b = dtable[exp][b][0], a = dtable[exp][a][0];
}


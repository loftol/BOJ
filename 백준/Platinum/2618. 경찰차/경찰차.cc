#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tii array<int, 3>
#define all(x) x.begin(), x.end()
#define INF (int)1e9
void solve() {
	int w, n; cin >> w >> n;
	vector<vector<tii>> table(n + 2, vector<tii>(n + 2, {INF, 0, 0}));
	vector<pii> arr(n + 2, {1, 1});
	arr[1] = { w, w };
	for (int i = 2; i <= n+1; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	auto dst = [&](pii a, pii b) {
		return abs(a[0] - b[0]) + abs(a[1] - b[1]);
	};

	queue<pii> q;
	q.push({ 0, 1 });
	tii ans = { INF,0,1 };
	table[0][1] = { 0,0,0 };
	while (q.size()) {
		auto [hx, hy] = q.front();
		q.pop();

		int next = max(hx, hy) + 1;
		int hdst = table[hx][hy][0];
		if (next == n + 2) {
			if (ans[0] > hdst) {
				ans = { hdst, hx, hy };
			}
			continue;
		}

		int ndst = dst(arr[next], arr[hy]);
		if (ndst + hdst < table[hx][next][0]) {
			if (table[hx][next][0] == INF) q.push({ hx, next });
			table[hx][next] = { ndst + hdst, hx, hy };
		}

		ndst = dst(arr[next], arr[hx]);
		if (ndst + hdst < table[next][hy][0]) {
			if (table[next][hy][0] == INF) q.push({ next, hy });
			table[next][hy] = { ndst + hdst, hx, hy };
		}
	}

	auto [val, hx, hy] = ans;
	cout << val << '\n';
	vector<int> stk;
	while (hx != 0 || hy != 1) {
		auto [pval, px, py] = table[hx][hy];
		if (hx != px) stk.push_back(1);
		else stk.push_back(2);
		hx = px, hy = py;
	}
	while (stk.size()) {
		cout << stk.back() << '\n';
		stk.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; //cin >> t;
	while (t--) solve();

	return 0;
}
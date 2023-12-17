#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tii array<int, 3>
#define all(x) x.begin(), x.end()
#define INF (int)1e9

void solve() {
	int n; cin >> n;
	vector<tii> points(n);
	int idx = 0;
	for (auto& [x, y, i] : points) {
		cin >> x >> y;
		i = idx++;
	}
	sort(all(points));
	auto OP = [&](pii a, pii b) {
		return (ll)a[0] * b[1] - (ll)b[0] * a[1];
	};
	auto ccw = [&](tii o, tii a, tii b) {
		pii u = { a[0] - o[0], a[1] - o[1] };
		pii v = { b[0] - o[0], b[1] - o[1] };
		ll op = OP(u, v);
		if (op) return op / abs(op);
		return op;
	};
	sort(points.begin() + 1, points.end(), [&](tii a, tii b) {
		ll cw = ccw(points[0], a, b);
		if(cw == 0) return a < b;
		return cw > 0;
		}
	);

	vector<tii> stk;
	stk.push_back(points.back());
	points.pop_back();
	while (ccw(points[0], stk.back(), points.back()) == 0) {
		stk.push_back(points.back());
		points.pop_back();
	}

	for (int i = 0; i < points.size(); i++) {
		cout << points[i][2] << ' ';
	}
	for (int i = 0; i < stk.size(); i++) {
		cout << stk[i][2] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; cin >> t;
	while (t--) solve();
	

	return 0;
}
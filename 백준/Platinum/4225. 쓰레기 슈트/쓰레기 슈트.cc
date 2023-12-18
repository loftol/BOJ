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
	vector<pii> points(n);
	for (auto& [x, y] : points) cin >> x >> y;
	sort(all(points));

	auto OP = [&](pii a, pii b) {
		return (ll)a[0] * b[1] - (ll)a[1] * b[0];
	};
	auto DOT = [&](pii a, pii b) {
		return (ll)a[0] * b[0] + (ll)a[1] * b[1];
	};

	auto CCW = [&](pii o, pii a, pii b) {
		pii u = { a[0] - o[0], b[0] - o[0] };
		pii v = { a[1] - o[1], b[1] - o[1] };
		ll op = OP(u, v);
		if (op) return op / abs(op);
		return op;
	};

	auto sub = [&](pii a, pii b) {
		return array{ a[0] - b[0], a[1] - b[1] };
	};



	sort(points.begin() + 1, points.end(), [&](pii a, pii b) {
		return CCW(points[0], a, b) == 1;
		});

	points.push_back(points[0]);
	vector<pii> ch = {points[0]};
	for (int i = 1; i < points.size(); i++) {
		pii c = points[i];
		while (ch.size() > 2) {
			pii b = ch.back();
			ch.pop_back();
			pii a = ch.back();
			if (CCW(a, b, c) == 1) {
				ch.push_back(b);
				break;
			}
		}
		ch.push_back(c);
	}
	ch.pop_back();
	int j = 0;
	double ans = 1e6;
	for (int i = 0; i < ch.size(); i++) {
		int ni = (i + 1) % ch.size(), nj = (j + 1) % ch.size();
		pii u = sub(ch[ni], ch[i]);
		pii v = sub(ch[nj], ch[j]);

		while (OP(u, v) >= 0) {
			j = nj;
			nj = (j + 1) % ch.size();
			v = sub(ch[nj], ch[j]);
		}

		pii w = sub(ch[j], ch[i]);
		ans = min(ans, ceil(abs(OP(u, w)) / sqrt(DOT(u, u))*100)/100);
	}
	cout << fixed;
	cout.precision(2);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1; //cin >> t;
	int n; cin >> n;
	while (n) {
		cout << "Case " << t++ << ": ";
		solve(n);
		cin >> n;
	}

	return 0;
}
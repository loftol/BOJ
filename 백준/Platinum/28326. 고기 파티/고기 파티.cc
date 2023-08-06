#include <bits/stdc++.h>
#include <array>
#define ll long long
#define pii array<ll, 3>
#define all(x) x.begin(), x.end()
using namespace std;

vector<vector<int>> seg;

int S = 1, n;
vector<pii> meat;
vector<int> used;

void init() {
	while (n > S) S <<= 1;
	seg = vector<vector<int>>(S * 2);
}

// 실제 쿼리가 아니지만 원래 세그에서 쿼리파트이므로 이름 유지
void query(int l, int r, int b, int e, int idx, int val) { 
	if (b >= l && e <= r) {
		seg[idx].push_back(val);
		return;
	}
	if (b >= r || e <= l) return;
	int mid = (b + e) / 2;
	query(l, r, b, mid, idx * 2, val);
	query(l, r, mid, e, idx * 2 + 1, val);
}

// 실제 업데이트가 아니지만 원래 세그에서 업데이트 파트이므로 이름 유지
vector<int> update(int a, int b) {
	vector<int> u, v;
	a += S;
	b += S;
	while (a && b) {
		if (a != b) {
			while (seg[a].size()) {
				int here = seg[a].back();
				seg[a].pop_back();
				if (!used[here]) {
					u.push_back(here);
				}
			}
			while (seg[b].size()) {
				int here = seg[b].back();
				seg[b].pop_back();
				if (!used[here]) {
					v.push_back(here);
				}
			}
		}
		else {
			while (seg[a].size()) {
				int here = seg[a].back();
				seg[a].pop_back();
				if (!used[here]) {
					u.push_back(here);
					v.push_back(here);
				}
			}
		}
		a /= 2, b /= 2;
	}

	sort(all(v));
	sort(all(u));

	vector<int> inter;
	set_intersection(all(v), all(u), back_inserter(inter));

	for (int i : v) used[i] = 1;
	for (int i : u) used[i] = 1;

	return inter;
}

void solve() {
	int m; cin >> n >> m;

	meat = vector<pii>(n);
	used = vector<int>(n);
	vector<int> co = { 0 };

	for (auto& [s, e, t] : meat) {
		cin >> s >> e >> t;
		e--;
		co.push_back(s);
		co.push_back(e);
	}

	vector<array<int, 2>> Q(m);
	for (auto& [i, j] : Q) {
		cin >> i >> j;
		co.push_back(i);
		co.push_back(j);
	}

	sort(all(co));
	co.erase(unique(all(co)), co.end());
	int nn = n;
	co.push_back(1000000001);
	n = co.size();
	init();

	for (int i = 0; i < nn; i++) {
		auto& [s, e, t] = meat[i];
		s = lower_bound(all(co), s) - co.begin();
		e = lower_bound(all(co), e) - co.begin();
		query(s, e + 1, 0, S, 1, i);
	}

	for(auto[a, b] : Q) {
		a = lower_bound(all(co), a) - co.begin();
		b = lower_bound(all(co), b) - co.begin();

		vector<int> inter = update(a, b);
		
		ll sum = 0;
		for (int i : inter) {
			sum += meat[i][2];
		}

		cout << sum << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int tc = 1; 
	//cin >> tc;
	while(tc--)
		solve();
	return 0;
}

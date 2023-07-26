#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>

#define ll long long
#define vi vector<int>
#define mat vector<vi>
#define pii pair<int, int>
#define tii array<int, 3>
#define all(v) v.begin(),v.end()
using namespace std;

mat buckets;
vector<vector<tii>> query(350);
vector<int> inp;
vector<pii> arr;
int n, k, S, m;

bool cmp(tii a, tii b) {
	return a[1] < b[1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	S = 350;

	inp = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) cin >> inp[i];

	arr = vector<pii>(n + 2);
	vector<int> pos(k + 1, -1);

	arr[1] = { 0, -1 };
	pos[0] = 1;

	for (int i = 1; i <= n; i++) {
		auto& [a, c] = arr[i + 1];
		a = (arr[i].first + inp[i]) % k;
		c = -1;
		if (pos[a] != -1) {
			arr[pos[a]].second = i + 1;
		}
		pos[a] = i + 1;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		b++;
		query[a / S].push_back({ a, b, i });
	}

	vector<tii> sec(k + 1, { -1,-1,-1 });
	vector<int> ans(m);
	for (int i = 0; i < S; i++) {
		vector<tii>& que = query[i];
		sort(all(que), cmp);

		priority_queue<tii> pq;

		if (que.empty()) continue;

		int s = que[0][0];
		int e = que[0][0] - 1;

		for (auto [a, b, idx] : que) {
			while (e < b) {
				e++;
				int val = arr[e].first;
				auto& [sv, ev, cv] = sec[val];
				if (cv < i) {
					cv = i;
					sv = ev = e;
				}
				else {
					ev = e;
				}
				pq.push({ ev - sv, sv, ev });
			}
			while (s > a) {
				s--;
				int val = arr[s].first;
				auto& [sv, ev, cv] = sec[val];
				if (cv < i) {
					cv = i;
					sv = ev = s;
				}
				else {
					sv = s;
				}
				pq.push({ ev - sv, sv, ev });
			}
			while (s < a) {
				int val = arr[s].first;
				auto& [sv, ev, cv] = sec[val];
				if (cv < i) {
					cv = i;
					sv = ev = arr[s].second;
				}
				else {
					sv = arr[s].second;
				}
				pq.push({ ev - sv, sv, ev });
				s++;
			}
			while (pq.top()[1] < a || pq.top()[2] > b) pq.pop();
			ans[idx] = pq.top()[0];

		}
	}

	for (int a : ans) cout << a << '\n';



	return 0;
}
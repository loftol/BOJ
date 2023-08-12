#include <bits/stdc++.h>
#include <array>
#include <random>

#define ll long long int
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> leftCnt(n * 2 + 1), rightCnt(n * 2 + 1);
	for (int i = 0; i < m; i++) {
		int x, d; cin >> x >> d;
		if (d == 1) rightCnt[x]++, rightCnt[x + n]++;
		else if (d == 0) leftCnt[x]++, leftCnt[x + n]++;
	}

	for (int i = 1; i <= 2 * n; i++) rightCnt[i] += rightCnt[i - 1], leftCnt[i] += leftCnt[i - 1];

	while (q--) {
		int p, x; cin >> x >> p; // 실수로 반대로 씀;;
		ll ans = p / m * (ll)n;
		p %= m;
		if (!p) p += m, ans -= n;
		int lo = 0, hi = n - 1;
		while (lo < hi) {
			int mid = (lo + hi - 1) / 2; // 가운데면 왼쪽을 선택시킴
			int sum = (rightCnt[x + mid] - rightCnt[x - 1]) + (leftCnt[n + x] - leftCnt[n + x - mid - 1]);
			if (sum >= p) hi = mid; // 오른쪽 당기기
			else lo = mid + 1; // 왼쪽 버리기
		}
		ans += lo;
		cout << ans << '\n';
	}

	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1; //cin >> tc;
	while (tc--) solve();


	return 0;
}
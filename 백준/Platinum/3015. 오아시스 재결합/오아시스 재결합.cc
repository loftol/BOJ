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
	vector<int> arr(n);
	for (int& i : arr) cin >> i;
	vector<pii> stk;

	ll cnt = 0;

	for (int i = 0; i < n; i++) {
		while (stk.size() && stk.back()[0] < arr[i]) {
			cnt += stk.back()[1];
			stk.pop_back();
		}
		if (stk.size() && stk.back()[0] == arr[i]) {
			int num = stk.back()[1];
			cnt += num;
			stk.pop_back();
			if (stk.size()) cnt++;
			stk.push_back({ arr[i], num + 1 });
		}
		else if (stk.size() && stk.back()[0] > arr[i]) {
			cnt++;
			stk.push_back({ arr[i], 1 });
		}
		else {
			stk.push_back({ arr[i], 1 });
		}
	}

	cout << cnt;
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
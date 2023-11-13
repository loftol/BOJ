#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define pii array<ll, 2>
#define tii array<int, 3>
#define pdd array<double, 3>
#define INF 1e9
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)

void solve() {
	int n; cin >> n;

	vector<ll> arr(n + 1); ll total = 0;
	for (int i = 1; i <= n; i++) cin >> arr[i], total += arr[i];
	
	vector<ll> arr2(n + 1);
	for (int i = 1; i <= n; i++) arr2[i] = total - arr[i] * n;
	
	vector<ll> psum(n + 1);
	for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + arr2[i];

	vector<pii> sorted_psum(n + 1);
	for (int i = 0; i <= n; i++) sorted_psum[i] = { psum[i], i };
	sort(all(sorted_psum));

	vector<ll> zero_psum(n + 1);
	for (int i = 1; i <= n; i++)
		zero_psum[i] = zero_psum[i - 1] + (!psum[i] ? 1 : 0);
	ll prev = -1e18, prei = -1;
	ll ps = 0;
	ll Maxps = 0;
	for (auto [val, idx] : sorted_psum) {
		if (val == 0) continue;
		if (prev != val) {
			ps = 1;
			prev = val;
		}
		else {
			ps -= zero_psum[idx] - zero_psum[prei];
			if (ps < 0) ps = 0;
			ps++;
			Maxps = max(ps, Maxps);
		}
		prei = idx;
	}

	Maxps = zero_psum[n] + max(0LL, Maxps - 1);
	cout << n - Maxps << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	for (int t = 1; t <= tc; t++) solve();
}

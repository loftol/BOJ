#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

void solve() {
	string str, pat;
	getline(cin, str);
	getline(cin, pat);

	int n = str.size(), m = pat.size();
	ll pat_hash = 0;
	ll top_val = 1;
	int base = 27;
	int MOD = (1 << 30) - 1;
	ll str_hash = 0;

	for (int i = 0; i < m; i++) {
		top_val *= base;
		top_val %= MOD;
		str_hash *= base, pat_hash *= base;
		str_hash += str[i], pat_hash += pat[i];
		pat_hash %= MOD, str_hash %= MOD;
	}

	vector<int> ret;
	if (str_hash == pat_hash) ret.push_back(0);

	top_val = MOD - top_val;

	for (int i = 1; i < n - m + 1; i++) {
		str_hash *= base;
		str_hash += str[i + m - 1];
		str_hash += top_val * str[i - 1];
		str_hash %= MOD;
		if (str_hash == pat_hash) ret.push_back(i);
	}

	cout << ret.size() << '\n';
	for (int& i : ret) cout << i + 1 << ' ';

	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	while (tc--) solve();
	return 0;
}
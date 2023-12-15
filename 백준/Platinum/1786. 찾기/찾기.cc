#include <bits/stdc++.h>
#include<array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>

void solve() {
	string pat, str;
	getline(cin, str);
	getline(cin, pat);
	int n = str.size(), m = pat.size();
	vector<int> fail(m + 1);
	
	for (int i = 1, j = 0; i < m; i++) {
		while (j && pat[i] != pat[j]) j = fail[j];
		if (pat[i] == pat[j]) fail[i + 1] = ++j;
	}

	vector<int> ret;
	for (int i = 0, j = 0; i < n; i++) {
		while (j && str[i] != pat[j]) j = fail[j];
		if (str[i] == pat[j]) j++;
		if (j == m) {
			ret.push_back(i - j + 1);
			j = fail[j];
		}
	}

	cout << ret.size() << '\n';
	for (int& i : ret) cout << i + 1 << '\n';

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
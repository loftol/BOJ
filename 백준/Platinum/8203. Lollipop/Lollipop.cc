#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define pii array<int, 2>
#define INF 1e9
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)

void solve(int t) {
	int n, q; cin >> n >> q;
	string str; cin >> str;
	bool reversed = false;
	string rstr = string(str.rbegin(), str.rend());
	if (str < rstr) {
		str = " " + rstr;
		reversed = true;
	}
	else str = " " + str;
	bool flag = false;
	vector<int> psum(n + 1);
	int total = 0;
	int pivot = n + 1;
	for (int i = 1; i <= n; i++) {
		if (str[i] == 'W' && !flag) {
			flag = true;
			pivot = i;
		}
		int add = (str[i] == 'W') ? 1 : 2;
		total += add;
		if (flag) {
			psum[i] = psum[i - 1] + add;
		}
	}
	
	while (q--) {
		int x; cin >> x;
		if (x > total || (x > psum[n] && (x - psum[n]) % 2)) {
			cout << "NIE\n";
			continue;
		}
		int l = 1, r = n;
		if (x >= psum[n]) {
			l = pivot - (x - psum[n]) / 2;
		}
		else {
			r = lower_bound(all(psum), x) - psum.begin();
			if (psum[r] != x) l = pivot + 1;
			else l = pivot;
		}
		if (reversed) {
			l = n + 1 - l;
			r = n + 1 - r;
			swap(l, r);
		}
		cout << l << ' ' << r << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int tc = 1; //cin >> tc;
	for (int t = 1; t <= tc; t++) solve(t);
}
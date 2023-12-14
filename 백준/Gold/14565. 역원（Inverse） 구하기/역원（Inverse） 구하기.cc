#include <bits/stdc++.h>
#include <array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define pll array<ll, 2>


pll eeu(ll a, ll b) { 
	if (a == 1) return { 0, 1 };
	else {
		auto [x, y] = eeu(b % a, a);
		return { y, x + b / a * y };
	}
}

void solve() {
	ll a, b; cin >> a >> b;
	ll g = gcd(a, b);
	ll s = a - b;
	ll p = -1;
	if (g == 1) {
		auto [x, y] = eeu(a, b);
		if (a * y > b * x) x *= -1;
		x %= a;
		x += a;
		x %= a;
		p = x;
	}
	cout << s << ' ' << p;
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
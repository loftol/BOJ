#include <bits/stdc++.h>
#include<array>

using namespace std;

#define pii array<int, 2>
#define ll long long
#define tll array<ll, 3>


tll eeu(ll a, ll b) { 
	if (a == 0) return { b, 1, 0 };
	else {
		auto [g, x, y] = eeu(b % a, a);
		return { g, y, x + b / a * y };
	}
}

void solve() {
	ll a, b; cin >> a >> b;
	ll s = a - b;
	
	auto [g, x, y] = eeu(a, b);
	if (a * y > b * x) x *= -1;
	x = (a + x) % a;
	ll p = (g - 1)? -1 : x;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()
int l, w, n, a, b, d;

void solve() {
	cin >> l >> w >> n;
	if (l * w % n) cout << "impossible";
	else {
		d = w * l / n;
		for (int i = 1; i <= d; i++)
			if (d % i == 0 && l % i == 0 && w % (d / i) == 0) {
				int j = d / i;
				for (int y = 0; y < l; y++) {
					for (int x = 0; x < w; x++) cout << (char)(y / i * (w / j) + x / j + 'A');
					cout << '\n';
				}
				return;
			}
	}
	return;
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
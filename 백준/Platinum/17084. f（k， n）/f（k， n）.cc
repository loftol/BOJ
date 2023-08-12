#include <iostream>
#include <vector>
#include <string>
#include <array>
#define ll long long
#define pii array<int, 2>
#define all(x) x.begin(), x.end()
using namespace std;

void solve() {
	int n, p;
	cin >> n >> p;
	
	vector<vector<ll>> T(p, vector<ll>(p));

	bool pos = true;

	ll a = 1, b = 1, tmp;
	int idx = 1;
	
	while (abs(a) <= 1e18) {
		tmp = b - a;
		b = a;
		a = tmp;
		idx--;
	}

	int lb = idx, rb = -idx;

	if (p == 1) {
		ll t; cin >> t;
		ll ans = 0;
		for (int i = lb; i <= rb + 1; i++) {
			if (a == t) {
				ans += max(0,(n - abs(i - 1)));
			}
			tmp = a + b;
			a = b;
			b = tmp;
		}
		cout << ans;
		return;
	}
	else {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cin >> T[i][j];
				if (i == 0 && j == 1) {
					bool pos = false;
					for (int k = lb; k <= rb + 1; k++) {
						if (a == T[0][0] && b == T[0][1]) {
							pos = true;
							idx = k;
							break;
						}
						tmp = a + b;
						a = b;
						b = tmp;
					}
					if (!pos) {
						cout << 0;
						return;
					}
				}
				else if (j >= 2) {
					if (T[i][j] != T[i][j - 1] + T[i][j - 2]) {
						cout << 0;
						return;
					}
				}
				else if (i > 0 && j == 0) {
					if (T[i][j] != T[i - 1][j + 1] - T[i - 1][j]) {
						cout << 0;
						return;
					}
				}
				else if (i > 0 && j >= 1) {
					if (T[i][j] != T[i - 1][j - 1]) {
						cout << 0;
						return;
					}
				}
			}
		}

		cout << max(n - abs(idx - 1) - p + 1, 0);
		
	}

	

	return;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int tc = 1;
	while(tc--)
		solve();

	return 0;
}

#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define tii array<ll, 3>
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'Y') adj[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (adj[i][j] == 1 && adj[j][i] == 1) {
				adj[i][j] = 0;
				adj[j][i] = 0;
			}
		}
	}

	for (int k = 0; k < n; k++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				adj[i][j] |= adj[i][k] & adj[k][j];
			
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j] == 1 && adj[j][i] == 1) {
				cout << "NO";
				return;
			}
		}
	}
	
	cout << "YES";

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	for (int t = 1; t <= tc; t++) solve();
}

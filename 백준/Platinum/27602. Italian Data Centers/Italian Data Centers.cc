#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define X first
#define Y second
#define all(v) v.begin(),v.end()
using namespace std;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<vector<ll>> even, odd;
vector<int> color;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	color = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	even = odd = vector<vector<ll>>(n + 1, vector<ll>(n + 1, 100000));
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (color[a] == color[b]) {
			even[a][b] = even[b][a] = 1;
		}
		else {
			odd[a][b] = odd[b][a] = 1;
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					odd[i][j] = min(even[i][k] + odd[k][j], odd[i][j]);
					odd[i][j] = min(odd[i][k] + even[k][j], odd[i][j]);
					even[i][j] = min(even[i][k] + even[k][j], even[i][j]);
					even[i][j] = min(odd[i][k] + odd[k][j], even[i][j]);
				}
			}
		}
	}

	ll M = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ll a = odd[i][j], b = even[i][j];
			if (a > b) swap(a, b);
			ll d = b - a;
			a = min(a + k, b + (k - d) / 2);
			if (a >= 100000) continue;
			M = max(M, a);
		}
	}

	cout << M;

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	//cin >> tc;
	while (tc--) solve();
	return 0;
}
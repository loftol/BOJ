#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define ld long double
#define tii array<ld, 3>
#define pld pair<ld, ld>
#define all(v) v.begin(),v.end()
using namespace std;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int n;

vector<tii> arr;

double subSolve(int z) {
	vector<tii> stk;
	ld result = 0;

	for (int i = 0; i < n; i++) {
		ld ncnt = 1, ns = arr[i][z], nss = arr[i][z] * arr[i][z];
		if (stk.size()) {
			auto [cnt, s, ss] = stk.back();
			while (stk.size() && ns / ncnt <= (s / cnt)) {
				ncnt += cnt, ns += s, nss += ss;
				stk.pop_back();
				if(stk.size())
					cnt = stk.back()[0], s = stk.back()[1], ss = stk.back()[2];
			}
		}
		stk.push_back({ ncnt, ns, nss });
	}

	for (auto [cnt, s, ss] : stk) {
		result += ss - s * s / cnt;
	}

	return result;
}

void solve()
{

	cin >> n;

	arr = vector<tii>(n);

	int idx = 0;
	for (auto& [i, x, y] : arr) {
		cin >> x >> y;
		i = idx++;
	}
	cout.precision(10);
	cout << fixed;
	cout << subSolve(1) + subSolve(2);

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1; //cin >> tc;
	while (tc--) solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <algorithm>
#define ll long long int
#define ld long double
#define pii array<int, 2>
#define X first
#define Y second
#define all(v) v.begin(),v.end()
using namespace std;
const ll INF = 1e15;
const ll MOD = 998244353;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void solve(){
	int B, C, D; cin >> B >> C >> D;
	int A1, A2; cin >> A1 >> A2;
	int E1, E2; cin >> E1 >> E2;

	int b, c, d;
	ll ans = 0;
	for (c = 1; c <= 1000000; c++) {
		int l1 = A1 * B / A2;
		int r1 = (c * B + C - 1) / C - 1;
		int l2 = c * D / C;
		int r2 = (E1 * D + E2 - 1) / E2 - 1;
		if (l1 >= r1 || l2 >= r2) continue;
		ans += (ll)(r1 - l1) * (r2 - l2);
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1; //cin >> tc;
	while(tc--) solve();
	return 0;
}
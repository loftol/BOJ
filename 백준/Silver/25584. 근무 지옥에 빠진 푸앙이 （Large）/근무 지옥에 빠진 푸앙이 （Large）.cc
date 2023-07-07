#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define ld long double
#define tii array<ld, 3>
#define pld pair<ld, ld>
#define all(v) v.begin(),v.end()
using namespace std;

int hashf(char c) {
	if (c == 'R') return 1;
	else if (c == 'G') return 2;
	else if (c == 'B') return 3;
	else return 0;
}

string revHash = " RGB";

string format1(int i, int j) {
	return "1 " + to_string(i) + ' ' + to_string(j);
}

string format2(int i, char a, char b) {
	return "2 " + to_string(i) + ' ' + a + ' ' + b;
}

void solve()
{
	int times[4] = { 4, 6, 4, 10 };

	map<string, int> mp;

	int n;
	cin >> n;
	for (int week = 0; week < n; week++) {
		for (int inv = 0; inv < 4; inv++) {
			for (int day = 0; day < 7; day++) {
				string str; cin >> str;
				mp[str] += times[inv];
			}
		}
	}

	int m = 1e9, M = 0;

	for (auto [_, len] : mp) {
		if (_ == "-") continue;
		M = max(M, len);
		m = min(m, len);
	}

	if (M - m <= 12) cout << "Yes";
	else cout << "No";

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1; //cin >> tc;
	while (tc--) solve();
	return 0;
}
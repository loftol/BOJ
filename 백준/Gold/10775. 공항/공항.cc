#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

vector<int> arr;

int find(int a) {
	if (arr[a] == a) return a;
	return arr[a] = find(arr[a]);
}

bool uni(int a, int b) {
	if ((a = find(a)) != (b = find(b))) {
		if (a > b) swap(a, b);
		return arr[b] = a;
	}
	return false;
}

void solve() {
	int g, p; cin >> g >> p;

	arr = vector<int>(g + 1);
	iota(all(arr), 0);
	int i = 0;
	for (; i < p; i++) {
		int a; cin >> a;
		if (!(a = find(a))) break;
		uni(a - 1, a);
	}
	cout << i;

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
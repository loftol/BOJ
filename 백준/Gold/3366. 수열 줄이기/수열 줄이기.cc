#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<array>

using namespace std;

#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<ll, 2>

vector<int> par;
vector<pii> lr;
int n;
int find(int a) {
	if (a >= n || a < 0) return a;
	if (par[a] != a) return par[a] = find(par[a]);
	return a;
}

void uni(int a, int b) { // b가 a 밑으로 들어가는 것에 주의 = a가 대푯값이 됨
	if (find(a) != find(b))
		par[par[b]] = par[a];
}

void solve() {
	cin >> n;
	
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	par = vector<int>(n);
	iota(all(par), 0);
	lr = vector<pii>(n);
	for (int i = 0; i < n; i++) {
		lr[i] = { i, i };
	}
	vector<pii> arri(n);
	for (int i = 0; i < n; i++) {
		arri[i] = { arr[i], i };
	}

	sort(all(arri));
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		auto [val, idx] = arri[i];
		int left = find(lr[idx][0] - 1);
		int right = find(lr[idx][1] + 1);
		int target;
		if (left < 0) target = right;
		else if (right >= n) target = left;
		else target = (arr[left] < arr[right]) ? left : right;
		sum += arr[target];
		uni(target, idx);
		lr[target][0] = min(lr[target][0], lr[idx][0]);
		lr[target][1] = max(lr[target][1], lr[idx][1]);
	}

	cout << sum;

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1; //cin >> tc;
	while (tc--) solve();
	return 0;
}
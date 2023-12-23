#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

ll A, N;

ll sumInverse() {
	return N - A;
}

ll getGcd(ll& x, ll& y, ll a, ll b) { // ax + by = 1을 찾는다 각각 초항은 A, N
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	
	ll gcd = getGcd(x, y, b % a, a);

	ll tmp = x;
	x = y - (b / a) * x;
	y = tmp;

	return gcd;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A;

	ll x = 0, y = 0;

	ll gcd = getGcd(x, y, A, N);

	ll ans2;

	if (gcd != 1) ans2 = -1;
	else { 
		ans2 = x % N; 
		if (x < 0) ans2 += N;
	}
	cout << sumInverse() << ' ' << ans2;
	return 0;
}
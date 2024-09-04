#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#define ll long long
#define vi vector<int>
#define MOD 200003

using namespace std;

vector<vi> hashed;
vi W;
int N;
string S;

int hashing(string sub) {
	int ret = 0;
	for (char c : sub) ret = (ret * 26 + (c - 'a')) % MOD;
	return ret;
}

int getW(int n) {
	ll ret = 1;
	ll a = 26;
	n--;
	while (n) {
		if (n & 1) (ret *= a) %= MOD;
		a *= a;
		a %= MOD;
		n >>= 1;
	}
	return ret;
}

bool rolling(int n) {
	hashed = vector<vi>(MOD);
	int now = hashing(S.substr(0, n));
	int begin = 0;
	int W = getW(n);
	while (begin + n < N) {
		hashed[now].push_back(begin);
		now = ((((now - (S[begin] - 'a') * W) % MOD + MOD) % MOD) * 26 + (S[begin + n] - 'a')) % MOD;
		begin++;
		if (hashed[now].size()) {
			for (int idx : hashed[now]) {
				if (!strncmp(&S[begin],&S[idx],n))
					return true;
			}
		}
	}
	return false;
}

int BS(int l, int r) {
	if (l + 1 == r) return l;
	int mid = (l + r) / 2;
	if (rolling(mid)) return BS(mid, r);
	else return BS(l, mid);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> N >> S;
	cout << BS(0, N);

	return 0;
}
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
	int n1, n2;
	string str1, str2;
	cin >> n1 >> str1 >> n2 >> str2;
	int xor1 = 0;
	for (char c : str1) xor1 ^= hashf(c);
	for (char c : str2) xor1 ^= hashf(c);
	if (xor1) {
		cout << -1; return;
	}

	int idx1 = 0, idx2 = 0;
	vector<string> Q;
	for (; idx2 < n2; idx2++) {
		if (str1[idx1] == str2[idx2]) {
			if (idx1 == str1.size() - 1 && idx2 != str2.size()) {
				char x = str1[idx1];
				char y = (x == 'R') ? 'G' : 'R';
				char z = revHash[hashf(x) ^ hashf(y)];
				Q.push_back(format2(idx2 + 1, y, z));
				Q.push_back(format2(idx2 + 1, x, z));
				str1.push_back(z); str1.push_back(z);
			}
			idx1++;
		}
		else {
			char a = str2[idx2];
			str1[idx1] = revHash[hashf(str1[idx1]) ^ hashf(str2[idx2])];
			char b = str1[idx1];
			Q.push_back(format2(idx2 + 1, a, b));
		}
	}

	string str(str1.begin() + idx1, str1.end());
	char c = str2.back();
	if(str.size())
		reverse(all(str));
	int pivot = str2.size();

	while (str.size()) {
		int e = (int)str.size() - 1;
		assert(str.size() != 1);
		char x = str[e], y = str[e - 1];
		if (x == y) {
			if (x == c) {
				char u = (x == 'R') ? 'G' : 'R';
				char v = revHash[hashf(x) ^ hashf(u)];
				Q.push_back(format2(pivot + 1, u, v));
				Q.push_back(format1(pivot + 2, pivot + 3));
			}
			Q.push_back(format1(pivot, pivot + 1));
			Q.push_back(format1(pivot, pivot + 1));
			str.pop_back(); str.pop_back();
		}
		else {
			char u = revHash[hashf(x) ^ hashf(y)];
			Q.push_back(format1(pivot + 1, pivot + 2));
			str.pop_back();
			str[e - 1] = u;
		}
	}

	cout << Q.size() << '\n';
	for (string q : Q) {
		cout << q << '\n';
	}

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1; //cin >> tc;
	while (tc--) solve();
	return 0;
}
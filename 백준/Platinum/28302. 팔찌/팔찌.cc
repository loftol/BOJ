#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <array>
#include <string>

using namespace std;

vector<int> str, str1, str2;

vector<string> queries, queries1, queries2;

char revHash(int X) {
	string st = " RGB";
	return st[X];
}

string format1(int a, int b, int c) {
	return to_string(a) + ' ' + to_string(b) + ' ' + to_string(c);
}

string format2(int a, int b, char c, char d) {
	return to_string(a) + ' ' + to_string(b) + ' ' + c + ' ' + d;
}

void SWAP(int a, int X, int Y) {
	queries.push_back(format1(1, a, a + 1));
	queries.push_back(format2(2, a, revHash(Y), revHash(X)));
	swap(str[a - 1], str[a]);
}

int XY(int a, int X, int Y) {
	queries.push_back(format1(1, a, a + 1));
	str.pop_back(), str.pop_back();
	str.push_back(X ^ Y);
	return (X ^ Y);
}

void XYY(int a, int X, int Y) {
	int Z = X ^ Y;
	queries.push_back(format1(1, a, a + 1));
	queries.push_back(format1(1, a, a + 1));
	str.pop_back(), str.pop_back();
}

void XXX(int a, int X) {
	int Y = (X == 1) ? 2 : 1;
	int Z = X ^ Y;
	queries.push_back(format2(2, a + 1, revHash(Y), revHash(Z)));
	queries.push_back(format1(1, a + 2, a + 3));
	XYY(a, X, Y);
}

void XX2YY(int a, int X, int Y) {
	int Z = X ^ Y;
	queries1.push_back(format2(2, a + 1, revHash(Z), revHash(Y)));
	queries1.push_back(format1(1, a, a + 1));
	str[a - 1] = Y, str[a] = Y;
}

void revSWAP(int a, int X, int Y) {
	SWAP(a, X, Y);
}

int revXY(int a, int X, int Y) {
	int Z = X ^ Y;
	queries.push_back(format2(2, a, revHash(X), revHash(Y)));
	str.pop_back(), str.pop_back();
	str.push_back(Z);
	return Z;
}

void revXXX(int a, int X) {
	int Y = (X == 1) ? 2 : 1;
	int Z = X ^ Y;
	queries.push_back(format1(1, a + 2, a + 3));
	queries.push_back(format2(2, a + 1, revHash(X), revHash(Y)));
	queries.push_back(format2(2, a, revHash(X), revHash(Z)));
	queries.push_back(format2(2, a, revHash(Y), revHash(Z)));
	str.pop_back(), str.pop_back();
}

void revXYY(int a, int X, int Y) {
	int Z = X ^ Y;
	queries.push_back(format2(2, a, revHash(X), revHash(Y)));
	queries.push_back(format2(2, a, revHash(Z), revHash(Y)));
	str.pop_back(), str.pop_back();
}

int hashf(char c) {
	if (c == 'R') return 1;
	if (c == 'G') return 2;
	if (c == 'B') return 3;
}

void subSolve1() {
	while (!((str.size() == 2 && (str[0] == str[1])) || str.size() == 1)) {
		int e = str.size() - 1;
		if (str[e] != str[e - 1]) XY(e, str[e - 1], str[e]);
		else {
			if (str[e - 1] != str[e - 2]) XYY(e - 1, str[e - 2], str[e - 1]);
			else XXX(e - 1, str[e - 2]);
		}
	}
	str1 = str;
	queries1 = queries;
}

void subSolve2() {
	while (!((str.size() == 2 && (str[0] == str[1])) || str.size() == 1)) {
		int e = str.size() - 1;
		if (str[e] != str[e - 1]) revXY(e, str[e - 1], str[e]);
		else {
			if (str[e - 1] != str[e - 2]) revXYY(e - 1, str[e - 2], str[e - 1]);
			else revXXX(e - 1, str[e - 2]);
		}
	}
	str2 = str;
	queries2 = vector<string>(queries.rbegin(), queries.rend());
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	
	for (char c : s) str.push_back(hashf(c));

	subSolve1();

	cin >> n >> s;
	str = vector<int>();
	queries = vector<string>();
	for (char c : s) str.push_back(hashf(c));
	
	subSolve2();

	if (str1.size() != str2.size()) {
		cout << -1;
		return;
	}

	if (str1.size() == 1) {
		if (str1[0] != str2[0]) {
			cout << -1;
			return;
		}
	}
	else {
		if (str1[0] != str2[0]) {
			XX2YY(1, str1[0], str2[0]);
		}
	}
	cout << queries1.size() + queries2.size() << '\n';
	for (string query : queries1) cout << query << '\n';
	for (string query : queries2) cout << query << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	solve();
	return 0;
}

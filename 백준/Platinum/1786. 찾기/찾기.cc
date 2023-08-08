#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;

vector<int> fail;

void makeFail(string& pat) {
	int i = 1, j = 0;
	fail = vector<int>(pat.size() + 1, 0);
	while (i + j < pat.size()) {
		if (!fail[i + j]) fail[i + j] = j;
		if (pat[i + j] == pat[j]) j++;
		else {
			if (j == 0) i++;
			else {
				i = i + j - fail[j];
				j = fail[j];
			}
		}
	}
	fail[i + j] = j;
}

vector<int> kmp(string& str, string& pat) {
	vector<int> ret;
	int i = 0, j = 0;
	while (i + j < str.size()) {
		if (j == pat.size()) {
			ret.push_back(i);
			i = i + j - fail[j];
			j = fail[j];
		}
		else if (str[i + j] == pat[j]) j++;
		else {
			if (j == 0) i++;
			else {
				i = i + j - fail[j];
				j = fail[j];
			}
		}
	}
	if (j == pat.size()) ret.push_back(i);

	return ret;
}

void solve() {
	string str, pat;
	getline(cin, str);
	getline(cin, pat);

	makeFail(pat);
	vector<int> ans = kmp(str, pat);

	cout << ans.size() << '\n';
	for (int& i : ans) cout << i + 1 << '\n';

	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	while (tc--) solve();
	return 0;
}
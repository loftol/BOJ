#include<bits/stdc++.h>
#include<array>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<int, 3>
#define tll array<ll, 3>
#define bs bitset<32>
#define INF 1e9
void solve() {
    vector<string> mat = {
        "aespa",
        "baekjoon",
        "cau",
        "debug",
        "edge",
        "firefox",
        "golang",
        "haegang",
        "iu",
        "java",
        "kotlin",
        "lol",
        "mips",
        "null",
        "os",
        "python",
        "query",
        "roka",
        "solvedac",
        "tod",
        "unix",
        "virus",
        "whale",
        "xcode",
        "yahoo",
        "zebra"
    };
    vector<int> mp = { 5, 8, 3, 5, 4, 7, 6, 7, 2, 4, 6, 3, 4, 4, 2, 6, 5, 4, 8, 3, 4, 5, 5, 5, 5, 5 };
    string str; cin >> str;
    string ans;
    for (int i = 0; i < str.size();) {
        ans.push_back(str[i]);
        for (int j = 0; j < mat[str[i] - 'a'].size(); j++) {
            if (str[i + j] != mat[str[i] - 'a'][j]) {
                cout << "ERROR!";
                return;
            }
        }
        i = i + mp[str[i] - 'a'];
    }
    cout << "It\'s HG!\n";
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while (t--) solve();
}
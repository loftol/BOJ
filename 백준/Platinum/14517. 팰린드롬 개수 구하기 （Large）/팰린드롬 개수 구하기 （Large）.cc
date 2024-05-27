#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define MAX (int)1e8
#define ll long long
#define tii array<int, 3>
#define pll array<ll, 2>


void solve() {
    string str; cin >> str;
    int n; n = str.size();
    vector<vector<int>> table(n, vector<int>(n, 0));
    for (int l = 0; l <= n - 1; l++) {
        for (int i = 0; i + l <= n - 1; i++) {
            int j = i + l;
            if (j - 1 >= i) table[i][j] += table[i][j - 1];
            if (i + 1 <= j) table[i][j] += table[i + 1][j];
            if (i + 1 <= j - 1 && str[i] != str[j]) table[i][j] += 10007 - table[i + 1][j - 1];
            if (str[i] == str[j]) table[i][j]++;
            table[i][j] %= 10007;
        }
    }
    cout << table[0][n - 1];
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
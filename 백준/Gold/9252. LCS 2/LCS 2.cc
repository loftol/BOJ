#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size(), m = str2.size();

    vector<vector<int>> table(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i < n && j < m && str1[i] == str2[j])
                table[i + 1][j + 1] = max(table[i + 1][j + 1], table[i][j] + 1);
            if(i < n)
                table[i + 1][j] = max(table[i + 1][j], table[i][j]);
            if(j < m)
                table[i][j + 1] = max(table[i][j + 1], table[i][j]);
        }
    }
    int i = n, j = m;
    cout << table[n][m] << '\n';
    string ans;
    while (i > 0 && j > 0) {
        if (i > 0 && j > 0 && table[i - 1][j - 1] == table[i][j] - 1 && str1[i - 1] == str2[j - 1]) {
            ans.push_back(str1[i - 1]);
            i--; j--;
        }
        else if (i > 0 && table[i - 1][j] == table[i][j]) i--;
        else j--;
    }

    while (ans.size()) {
        cout << ans.back();
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
}
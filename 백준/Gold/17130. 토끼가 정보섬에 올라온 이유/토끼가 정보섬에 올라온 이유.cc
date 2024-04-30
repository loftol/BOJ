#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)998244353

void solve() {
    int n, m; cin >> n >> m;
    vector<string> board(n);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int ti = 0, tj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') dp[i][j] = 0;
        }
    }

    for (int j = 0; j < m-1; j++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][j] == -1) continue;
            if (i + 1 < n && board[i+1][j+1] != '#') {
                if(board[i + 1][j + 1] == 'C')
                    dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
                else
                    dp[i + 1][j + 1] = max(dp[i][j], dp[i + 1][j + 1]);
            }
            if (board[i][j+1] == 'C' )
                dp[i][j+1] = max(dp[i][j] + 1, dp[i][j+1]);
            else if(board[i][j + 1] != '#')
                dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
            if (i - 1 >= 0 && board[i - 1][j + 1] != '#') {
                if (board[i - 1][j + 1] == 'C' )
                    dp[i - 1][j + 1] = max(dp[i][j] + 1, dp[i - 1][j + 1]);
                else
                    dp[i - 1][j + 1] = max(dp[i][j], dp[i - 1][j + 1]);
            }
        }
    }

    int Mans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') Mans = max(Mans, dp[i][j]);
        }
    }
    cout << Mans;
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

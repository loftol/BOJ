#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
using namespace std;

void solve() {
    vector<vector<bs>> sqrState(3, vector<bs>(3));
    vector<bs> rowState(9), colState(9);

    vector<string> board(9);
    for (string& str : board) cin >> str;
    int n = 9;
    bs fullState = ((1 << 9) - 1) << 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = board[i][j] - '0';
            if (val) {
                sqrState[i / 3][j / 3][val] = 1;
                rowState[i][val] = 1;
                colState[j][val] = 1;
            }
        }
    }

    function<bool(int, int)> track = [&](int i, int j) {
        if (i == 9) {
            return true;
        }
        int nj = (j + 1) % 9;
        int ni = i + (nj ? 0 : 1);
        if (board[i][j] != '0') return track(ni, nj);
        bs cellState = sqrState[i / 3][j / 3] | rowState[i] | colState[j];
        for (int val = 1; val <= 9; val++) {
            if (!cellState[val]) {
                sqrState[i / 3][j / 3][val] = rowState[i][val] = colState[j][val] = 1;
                board[i][j] = '0' + val;
                if (track(ni, nj))
                    return true;
                sqrState[i / 3][j / 3][val] = rowState[i][val] = colState[j][val] = 0;
                board[i][j] = '0';
            }
        }
        return false;
    };

    track(0, 0);
    for (string str : board) cout << str << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while(t--) solve();
    
    return 0;
}
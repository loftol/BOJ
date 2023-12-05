#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>
void solve() {
    int n, m; cin >> n >> m;
    vector<string> board(n); for (string& str : board) cin >> str;
    vector<vector<int>> vst(n, vector<int>(m));
    vector<vector<int>> ans = vst;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    function<int(int, int, int)> counter = [&](int i, int j, int x) {
        int ret = 1;
        for (int dir = 0; dir < 4; dir++) {
            vst[i][j] = x;
            int ni = i + dx[dir], nj = j + dy[dir];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && vst[ni][nj] != x && board[ni][nj] != '1')
                ret += counter(ni, nj, x);
        }
        return ret;
    };

    function<void(int, int, int, int)> propa = [&](int i, int j, int x, int val) {
        vst[i][j] = x;
        if (board[i][j] == '1') {
            ans[i][j] += val;
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            int ni = i + dx[dir], nj = j + dy[dir];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && vst[ni][nj] != x) {
                propa(ni, nj, x, val);
            }
        }
    };
    int xcnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vst[i][j] == 0 && board[i][j] == '0') {
                int val = counter(i, j, xcnt++);
                propa(i, j, xcnt++, val);
            }
            else if (board[i][j] == '1') ans[i][j] += 1;
        }
    }

    for (auto row : ans) {
        for (int i : row) {
            cout << i % 10;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
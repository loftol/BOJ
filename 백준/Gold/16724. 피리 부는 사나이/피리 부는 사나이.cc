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
    map<char, int> dx = { {'R', 0}, {'U', -1}, {'L',0}, {'D', 1} };
    map<char, int> dy = { {'R', 1}, {'U', 0}, {'L', -1}, {'D', 0} };
    function<int(int, int)> dfs = [&](int i, int j) {
        if (vst[i][j] == 2) return 0;
        if (vst[i][j] == 1) return 1;
        vst[i][j] = 1;
        char dir = board[i][j];
        int ni = i + dx[dir], nj = j + dy[dir];
        int ret = dfs(ni, nj);
        vst[i][j] = 2;
        return ret;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += dfs(i, j);
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
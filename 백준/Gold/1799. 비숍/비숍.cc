#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<vector<int>> board0(n, vector<int>(n));
    vector<vector<int>> board1 = board0, board2(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = (i + j) / 2, y = (j - i + n + 1) / 2 - 1;
            if ((i + j) % 2 == 0) {
                cin >> board1[x][y];
            }
            else {
                cin >> board2[x][y];
            }
        }
    }

    vector<int> state(n);
    function<int(int,vector<vector<int>>&)> track = [&](int here, vector<vector<int>>& board) {
        int ret = 0;
        if (here == n) return 0;
        ret = track(here + 1, board);
        for (int i = 0; i < n; i++) {
            if (board[here][i] && !state[i]) {
                state[i] = 1;
                ret = max(ret, track(here + 1, board) + 1);
                state[i] = 0;
            }
        }
        return ret;
    };

    cout << track(0, board1) + track(0, board2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
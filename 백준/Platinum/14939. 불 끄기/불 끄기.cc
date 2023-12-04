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
    vector<string> board(10);
    for (string& str : board) cin >> str;
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    auto click = [&](int i, int j, vector<string>& boa) {
        for (int dir = 0; dir < 4; dir++) {
            int ni = i + dx[dir], nj = j + dy[dir];
            if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10) {
                boa[ni][nj] = (boa[ni][nj] == '#' ? 'O' : '#');
            }
        }
        boa[i][j] = (boa[i][j] == '#' ? 'O' : '#');
    };
    int minClick = -1;
    for (int i = 0; i < (1 << 10); i++) {
        vector<string> newBoard = board;
        int clickNum = 0;
        int ii = i;
        int j = 0;
        while (ii >= (1 << j)) {
            if (ii & (1 << j)) {
                click(0, j, newBoard);
                clickNum++;
            }
            j++;
        }
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 10; k++) {
                if (newBoard[j][k] == 'O') {
                    click(j + 1, k, newBoard);
                    clickNum++;
                }
            }
        }
        bool pos = true;
        for (int k = 0; k < 10; k++) {
            if (newBoard[9][k] == 'O') pos = false;
        }
        if (pos) {
            if (minClick == -1) minClick = clickNum;
            else minClick = min(minClick, clickNum);
        }
    }

    cout << minClick;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
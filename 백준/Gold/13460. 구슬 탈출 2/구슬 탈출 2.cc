#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>
int solve() {
    int n, m; cin >> n >> m;

    vector<string> board;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        board.push_back(str);
    }
    
    int ri = 0, rj = 0, bi = 0, bj = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                ri = i, rj = j;
            }
            else if (board[i][j] == 'B') {
                bi = i, bj = j;
            }
        }
    }

    vector<vector<vector<vector<int>>>> vst(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));

    queue<fii> q;
    q.push({ ri, rj, bi, bj });

    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { -1, 0, 1, 0 };
    vst[ri][rj][bi][bj] = 0;
    while (q.size()) {
        auto [rx, ry, bx, by] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;

            bool rhole = false, bhole = false;
            while (true) {
                if (board[nrx][nry] == 'O') { rhole = true; break; }
                if (board[nrx + dx[dir]][nry + dy[dir]] != '#' && !(nrx + dx[dir] == nbx && nry + dy[dir] == nby)) {
                    nrx += dx[dir];
                    nry += dy[dir];
                }
                else break;
            }

            
            while (true) {
                if (board[nbx][nby] == 'O') { bhole = true; break; }
                if (board[nbx + dx[dir]][nby + dy[dir]] != '#' && !(nbx + dx[dir] == nrx && nby + dy[dir] == nry && !rhole)) {
                    nbx += dx[dir];
                    nby += dy[dir];
                }
                else break;
            }

            while (true) {
                if (board[nrx][nry] == 'O') { rhole = true; break; }
                if (board[nrx + dx[dir]][nry + dy[dir]] != '#' && !(nrx + dx[dir] == nbx && nry + dy[dir] == nby && !bhole)) {
                    nrx += dx[dir];
                    nry += dy[dir];
                }
                else break;
            }

            if (vst[nrx][nry][nbx][nby] == -1) {
                vst[nrx][nry][nbx][nby] = vst[rx][ry][bx][by] + 1;
                if (rhole && !bhole) return vst[nrx][nry][nbx][nby];
                if(!rhole && !bhole && vst[nrx][nry][nbx][nby] <= 9)
                    q.push({ nrx, nry, nbx, nby });
            }
            
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cout << solve();
    }
}
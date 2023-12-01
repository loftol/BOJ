#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pii>> doors(26);
    vector<int> key(26);
    vector<vector<int>> vst(n + 2, vector<int>(m + 2));
    vector<string> board = { string(m + 2, '.') };
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        str = '.' + str + '.';
        board.push_back(str);
    }
    board.push_back(string(m + 2, '.'));

    queue<pii> q;
    q.push({ 0, 0 });
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    string str; cin >> str;
    if(str != "0")
        for (char c : str) key[c - 'a'] = 1;
    int ans = 0;
    while (q.size()) {
        auto [hx, hy] = q.front();
        if (board[hx][hy] == '$') ans++;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = hx + dx[dir], ny = hy + dy[dir];
            if (nx >= 0 && nx < n + 2 && ny >= 0 && ny < m + 2) {
                if (vst[nx][ny] || board[nx][ny] == '*') continue;
                vst[nx][ny] = 1;
                if (board[nx][ny] == '.' || board[nx][ny] == '$') {
                    q.push({ nx, ny });
                }
                else {
                    char c = board[nx][ny];
                    if (c >= 'a' && c <= 'z') {
                        key[c - 'a'] = 1;
                        while (doors[c - 'a'].size()) {
                            q.push({ doors[c - 'a'].back() });
                            doors[c - 'a'].pop_back();
                        }
                        q.push({ nx, ny });
                    }
                    else if (key[c - 'A']) {
                        q.push({ nx, ny });
                    }
                    else {
                        doors[c - 'A'].push_back({ nx, ny });
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
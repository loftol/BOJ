#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define sii array<int, 6>
void solve() {
    int r, c, m; cin >> r >> c >> m;
    vector<sii> sharks(m);
    for (auto& [x, y, s, d, z, _] : sharks) cin >> x >> y >> s >> d >> z;
    sort(all(sharks), [&](sii a, sii b) {
        return a[4] < b[4];
        });
    vector<vector<int>> board(r, vector<int>(c, -1));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0, 1, -1 };
    auto move = [&](sii& shark) {
        auto& [x, y, s, d, z, _] = shark;
        int mod1 = 2 * (r - 1), mod2 = 2 * (c - 1);
        if (d == 0) {
            x = mod1 - x;
            d = 1;
        }
        x = (x + (mod1 + dx[d]) * s) % mod1;
        if (d == 1 && x > mod1 - x) d = 0;
        else if (d == 0 && x < mod1 - x) d = 1;
        x = min(x, mod1 - x);

        if (d == 3) {
            y = mod2 - y;
            d = 2;
        }
        y = (y + (mod2 + dy[d]) * s) % mod2;
        if (d == 2 && y > mod2 - y) d = 3;
        else if (d == 3 && y < mod2 - y) d = 2;
        y = min(y, mod2 - y);
    };

    for (int i = 0; i < m; i++){
        auto& [x, y, s, d, z, _] = sharks[i];
        x--, y--;
        d--;
        board[x][y] = i;
    }
    int ans = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (board[j][i] != -1 && !sharks[board[j][i]][5]) {
                ans += sharks[board[j][i]][4];
                sharks[board[j][i]][5] = 1;
                board[j][i] = -1;
                break;
            }
        }

        for (int j = 0; j < m; j++) {
            sii& shark = sharks[j];
            if (shark[5]) continue;
            auto& [x, y, s, d, z, e] = shark;
            if (board[x][y] == j) board[x][y] = -1;
            move(shark);
            if (board[x][y] != -1 && board[x][y] < j) {
                sharks[board[x][y]][5] = 1;
            }
            board[x][y] = j;
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
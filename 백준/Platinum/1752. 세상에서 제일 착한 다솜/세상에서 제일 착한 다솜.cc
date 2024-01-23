#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>

void solve() {
    int r, c; cin >> r >> c;

    int n; cin >> n;
    vector<pii> V;
    vector<vector<bool>> board(r + 1, vector<bool>(c + 1));
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        V.push_back({ x, y });
        board[x][y] = 1;
    }

    sort(all(V));
    int M = 0;
    auto isIn = [&](int x, int y) {
        return x > 0 && y > 0 && x <= r && y <= c;
    };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [u1, v1] = V[i];
            auto [u2, v2] = V[j];
            int dx = u2 - u1;
            int dy = v2 - v1;
            if (!isIn(u1 - dx, v1 - dy)) {
                int cnt = 1;
                bool flag = true;
                //cout << u1 << ' ' << v1 << '\n';
                while (isIn(u2, v2) && (flag &= board[u2][v2])) {
                    //cout << u2 << ' ' << v2 << '\n';
                    cnt++;
                    u2 += dx;
                    v2 += dy;
                }

                //cout << u2 << ' ' << v2 << '\n' << '\n' << '\n';
                if (flag) {
                    M = max(M, cnt);
                }
            }
        }
    }
    if (M < 3) M = 0;
    cout << M;
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
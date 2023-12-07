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
    int n, m; cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    vector <function<int(int, int)>> filters(5);
    
    filters[0] = [&](int i, int j) {return 0; };
    filters[1] = [&](int i, int j) {
        if (j - 1 < 0) return 0;
        return board[i][j - 1];
    };
    filters[2] = [&](int i, int j) {
        if (i - 1 < 0) return 0;
        return board[i - 1][j];
    };
    filters[3] = [&](int i, int j) {
        return (filters[1](i, j) + filters[2](i, j)) / 2;
    };
    filters[4] = [&](int i, int j) {
        int c = (i - 1 >= 0 && j - 1 >= 0) ? board[i - 1][j - 1] : 0;
        return filters[1](i, j) + filters[2](i, j) - c;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            int used = -1;
            int minV = 1e9;
            for (int k = 0; k < 5; k++) {
                if (abs(minV) > abs(filters[k](i, j) - board[i][j])) {
                    minV = board[i][j] - filters[k](i, j);
                    used = k;
                }
            }
            cout << used << ' ' << minV << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
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
    vector<vector<int>> board(n, vector<int>(n));
    for (auto& row : board) for (int& val : row) cin >> val;
    
    function<int(int, vector<vector<int>>)> dfs = [&](int depth, vector<vector<int>> board) {
        if (depth == 5) {
            int M = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    M = max(M, board[i][j]);
                }
            }
            return M;
        }

        int ret = 0;
        vector<vector<int>> newBoard(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            vector<pii> stk;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) continue;
                if (stk.size() == 0 || stk.back()[1] || stk.back()[0] != board[i][j])
                    stk.push_back({ board[i][j] , 0 });
                else {
                    stk.pop_back();
                    stk.push_back({ 2 * board[i][j], 1 });
                }
            }
            for (int j = 0; j < stk.size(); j++) {
                newBoard[i][j] = stk[j][0];
            }
        }
        ret = max(ret, dfs(depth + 1, newBoard));

        newBoard = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            vector<pii> stk;
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 0) continue;
                if (stk.size() == 0 || stk.back()[1] || stk.back()[0] != board[i][j])
                    stk.push_back({ board[i][j] , 0 });
                else {
                    stk.pop_back();
                    stk.push_back({ 2 * board[i][j], 1 });
                }
            }
            for (int j = 0; j < stk.size(); j++) {
                newBoard[i][n - 1 - j] = stk[j][0];
            }
        }
        ret = max(ret,dfs(depth + 1, newBoard));

        newBoard = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            vector<pii> stk;
            for (int j = 0; j < n; j++) {
                if (board[j][i] == 0) continue;
                if (stk.size() == 0 || stk.back()[1] || stk.back()[0] != board[j][i])
                    stk.push_back({ board[j][i] , 0 });
                else {
                    stk.pop_back();
                    stk.push_back({ 2 * board[j][i], 1 });
                }
            }
            for (int j = 0; j < stk.size(); j++) {
                newBoard[j][i] = stk[j][0];
            }
        }
        ret = max(ret, dfs(depth + 1, newBoard));

        newBoard = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            vector<pii> stk;
            for (int j = n - 1; j >= 0; j--) {
                if (board[j][i] == 0) continue;
                if (stk.size() == 0 || stk.back()[1] || stk.back()[0] != board[j][i])
                    stk.push_back({ board[j][i] , 0 });
                else {
                    stk.pop_back();
                    stk.push_back({ 2 * board[j][i], 1 });
                }
            }
            for (int j = 0; j < stk.size(); j++) {
                newBoard[n - 1 - j][i] = stk[j][0];
            }
        }
        ret = max(ret, dfs(depth + 1, newBoard));

        return ret;
    };
    cout << dfs(0, board);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
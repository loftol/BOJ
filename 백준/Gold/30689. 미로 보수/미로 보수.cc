#include<iostream>
#include<string>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
#include<array>
using namespace std;
int INF = 50000000;
#define all(x) x.begin(), x.end()
#define pii array<long long, 2>
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
vector<vector<int>> vst, comp, board, cost;
int n, m;

int dfs(int hx, int hy) {
    int nx = hx + dx[board[hx][hy]], ny = hy + dy[board[hx][hy]];
    if (vst[hx][hy] >= 2) return cost[hx][hy];
    vst[hx][hy]++;
    int ret = 0;
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (comp[nx][ny]) {
            comp[hx][hy] = 1;
            return 0;
        }
        if (vst[hx][hy] >= 2) {
            ret = min(dfs(nx, ny), cost[hx][hy]);
        }
        else {
            ret = dfs(nx, ny);
        }
    }
    else {
        ret = 0;
    }
    comp[hx][hy] = 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    board = vst = cost = comp = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            char a; a = str[j];
            if (a == 'L') board[i][j] = 0;
            if (a == 'U') board[i][j] = 1;
            if (a == 'R') board[i][j] = 2;
            if (a == 'D') board[i][j] = 3;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    
    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!comp[i][j])
                total += dfs(i, j);
        }
    }
    cout << total;
    return 0;
}
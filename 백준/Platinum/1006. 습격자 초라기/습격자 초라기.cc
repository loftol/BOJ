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
    int n, w; cin >> n >> w;
    vector<vector<int>> arr(2, vector<int>(n));
    vector<vector<vector<int>>> table(4, vector<vector<int>>(n, vector<int>(4, -1)));
    vector<vector<int>> canMerge(3, vector<int>(n + 1));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        if (arr[0][i] + arr[0][ni] <= w) canMerge[0][i] = 1;
        if (arr[1][i] + arr[1][ni] <= w) canMerge[1][i] = 1;
        if (arr[0][i] + arr[1][i] <= w) canMerge[2][i] = 1;
    }

    

    if (canMerge[0][n-1])
        table[1][0][1] = 1;
    if (canMerge[1][n-1])
        table[2][0][2] = 1;
    if (canMerge[0][n-1] && canMerge[1][n - 1])
        table[3][0][3] = 2;
    if (canMerge[2][n - 1])
        table[3][0][0] = 1;
    table[0][0][0] = 0;

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < 4; k++) {
                if (table[i][j][k] == -1) continue;
                table[i][j + 1][0] = max(table[i][j + 1][0], table[i][j][k]);

                if (k == 0 && canMerge[2][j])
                    table[i][j + 1][0] = max(table[i][j + 1][0], table[i][j][k] + 1);

                if(k == 0 && canMerge[0][j] && canMerge[1][j])
                    table[i][j + 1][3] = max(table[i][j + 1][3], table[i][j][k] + 2);

                if (!(k & 1) && canMerge[0][j])
                    table[i][j + 1][1] = max(table[i][j + 1][1], table[i][j][k] + 1);

                if (!(k & 2) && canMerge[1][j])
                    table[i][j + 1][2] = max(table[i][j + 1][2], table[i][j][k] + 1);
            }
        }
        for (int k = 0; k < 3; k++) {
            if (!(i & k)) ans = max(ans, table[i][n - 1][k]);
        }
        
        
    }
    cout << 2 * n - ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define pii array<int, 2>
#define tii array<int, 3>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
#define mat vector<vector<ll>>
using namespace std;

void solve() {
    int d; 
    cin >> d;
    vector<mat> table(1, mat(8, vector<ll>(8)));
    table[0][0][1] = table[0][0][2] = 1;
    table[0][1][0] = table[0][1][2] = table[0][1][3] = 1;
    table[0][2][0] = table[0][2][1] = table[0][2][3] = table[0][2][4] = 1;
    table[0][3][1] = table[0][3][2] = table[0][3][4] = table[0][3][5] = 1;
    table[0][4][2] = table[0][4][3] = table[0][4][5] = table[0][4][6] = 1;
    table[0][5][3] = table[0][5][4] = table[0][5][7] = 1;
    table[0][6][4] = table[0][6][7] = 1;
    table[0][7][5] = table[0][7][6] = 1;

    auto matProd = [&](mat a, mat b) {
        mat ret = mat(8, vector<ll>(8));
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    ret[i][j] += a[i][k] * b[k][j];
                    ret[i][j] %= 1000000007;
                }
            }
        }
        return ret;
    };

    for (int i = 1; i <= 30; i++) {
        table.push_back(matProd(table.back(), table.back()));
    }

    int idx = 0;
    mat start = mat(8, vector<ll>(8));
    start[0][0] = 1;
    while (d) {
        if (d & 1) {
            start = matProd(start, table[idx]);
        }
        d >>= 1;
        idx++;
    }

    cout << start[0][0];

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while(t--) solve();
    
    return 0;
}
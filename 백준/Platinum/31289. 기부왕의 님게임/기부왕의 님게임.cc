#include<bits/stdc++.h>
#include<array>
using namespace std;
#define ll long long
int table[201][201][201];
void solve() {
    int x, y, z; cin >> x >> y >> z;
    int a = table[x][y][z];
    int b = x + y + z - a;
    if ((x ^ y ^ z) == 0) {
        swap(a, b);
    }
    cout << b * 10000 << ' ' << a * 10000 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    table[0][0][0] = 0;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 200; k++) {
                int& ret = table[i][j][k];
                if (i ^ j ^ k) {
                    ret = 1000;
                    if ((j ^ k) < i) ret = min(ret, table[j ^ k][j][k]);
                    if ((i ^ k) < j) ret = min(ret, table[i][i ^ k][k]);
                    if ((j ^ i) < k) ret = min(ret, table[i][j][i ^ j]);
                }
                else {
                    ret = 0;
                    for (int ii = 0; ii < i; ii++) {
                        ret = max(ret, table[ii][j][k] + i - ii);
                    }
                    for (int jj = 0; jj < j; jj++) {
                        ret = max(ret, table[i][jj][k] + j - jj);
                    }
                    for (int kk = 0; kk < k; kk++) {
                        ret = max(ret, table[i][j][kk] + k - kk);
                    }
                }
            }
        }
    }

    int t = 1; cin >> t;
    while (t--) solve();
}
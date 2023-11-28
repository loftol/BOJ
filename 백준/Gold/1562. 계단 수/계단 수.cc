#include<iostream>
#include<string>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
#include<array>
#include<set>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 3>



void solve() {
    int n; cin >> n;
    vector<vector<vector<int>>> table(n, vector<vector<int>>(10, vector<int>(1 << 10)));
    for (int j = 1; j < 10; j++) {
        table[0][j][(1 << j)] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 1; k < (1 << 10); k++) {
                if (j + 1 < 10) {
                    table[i + 1][j + 1][k | (1 << (j + 1))] += table[i][j][k];
                    table[i + 1][j + 1][k | (1 << (j + 1))] %= (int)1e9;
                }
                if (j - 1 >= 0) {
                    table[i + 1][j - 1][k | (1 << (j - 1))] += table[i][j][k];
                    table[i + 1][j - 1][k | (1 << (j - 1))] %= (int)1e9;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += table[n - 1][i][(1 << 10) - 1];
        ans %= (int)1e9;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
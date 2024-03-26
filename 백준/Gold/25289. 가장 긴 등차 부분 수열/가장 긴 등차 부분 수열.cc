#include<bits/stdc++.h>
#include<array>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define bs bitset<32>
#define INF 1e9
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> table(101, vector<int>(201));
    for (int& i : a) cin >> i;
    int M = 1;
    for (int i : a) {
        for (int j = i - 100; j <= i - 1; j++) {
            if (table[i - j][j+100]) {
                table[i][j+100] = max(table[i][j+100], table[i - j][j+100] + 1);
                M = max(M, table[i][j+100]);
            }
        }
        for (int j = -100; j <= 100; j++) {
            table[i][j+100] = max(table[i][j+100], 1);
        }
    }
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
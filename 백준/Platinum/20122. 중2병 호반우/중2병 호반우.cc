#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<int, 3>
#define tll array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)1e9+7

void solve() {
    int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
    vector<vector<int>> board(n, vector<int>(m, -1));
    vector<int> people;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            if (x > 0) {
                pii a;
                people.push_back(x);
                board[i][j] = people.size() - 1;
            }
        }
    }

    //for (auto v : board) {  for (int i : v) {cout << i << ' '; } cout << '\n'; }
    //for (auto pe : people) { for (int i : pe) { cout << i << ' '; } cout << '\n'; }
    vector<vector<int>> lines;
    for (int i = 0; i < n; i++) lines.push_back(board[i]);
    for (int j = 0; j < m; j++) {
        lines.push_back({});
        for (int i = 0; i < n; i++) lines.back().push_back(board[i][j]);
    }
    //for (auto pe : lines) { for (int i : pe) { cout << i << ' '; } cout << '\n'; }

    int add[3] = { 0, a, b };
    int k = n + m;
    // cout << k << '\n';
    vector<tll> dp(1 << k, { -MAX, MAX, 1LL }); // {max, min, 3-killed}
    vector<bitset<100>> killed(1 << k);
    dp[0] = { 0, 0, 1 };
    ll mans = 0;
    ll Mans = 0;

    for (int bs = 0; bs < (1 << k); bs++) {
        auto [Mscore, mscore, prod] = dp[bs];
        for (int i = 0; i < k; i++) {
            if (bs & (1 << i)) continue;
            ll sscore = 0;
            ll pprod = prod;
            bitset<100> kb = killed[bs];
            for (int p : lines[i]) {
                //cout << sscore << '\n';
                if (p == -1) continue;
                bitset<100> uu;
                uu[p] = 1;
                if ((kb & uu).any()) continue;

                // 죽이기
                if (people[p] == 3) {
                    pprod *= c;
                }
                else {
                    sscore += add[people[p]] * pprod;
                }
                kb |= uu;
            }
            //cout << kb << '\n';
            int bbs = bs | (1 << i);
            dp[bbs][0] = max(dp[bbs][0], Mscore + sscore);
            dp[bbs][1] = min(dp[bbs][1], mscore + sscore);
            dp[bbs][2] = pprod;
            mans = min(mans, dp[bbs][1]);
            Mans = max(Mans, dp[bbs][0]);
            killed[bbs] |= kb;
        }
    }
    //for (auto pe : killed)  cout << pe << '\n';
   //for (auto [Mb, mb, pp] : dp) cout << Mb << ' ' << mb << ' '<< pp << '\n';
   cout << mans << ' ' << Mans;
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
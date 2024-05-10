#include<bits/stdc++.h>
#include<array>
#include<bit>
#define all(v) v.begin(),v.end()
using namespace std;
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n, m, s, e, t; cin >> n >> m >> s >> e >> t;
    vector<vector<int>> cost(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> cost[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j < s; j++) cost[i].push_back(0);
    for (int i = 1; i <= n; i++) for (int j = 1; j < m + s; j++) cost[i][j] += cost[i][j - 1];
    vector<int> block(n + 1); for (int i = 1; i <= n; i++) cin >> block[i];

    vector<deque<pii>> dqs(n + 1, {{ 0, 1 }}); // 값, 강좌
    vector<vector<pii>> dp(n + 1, vector<pii>(m + s+1, { (int)1e9,-1 }));

    for (int i = s; i < m + s; i++) {
        vector<tii> v;
        // gmin[i]는 deque으로부터 초기화 해온다.
            
        /*/ debug 0
        for (int j = 1; j <= n; j++) {
            cout << '(' << dqs[j].front()[0] << ',' << dqs[j].front()[1] << ')' << ' ';
        }
        cout << '\n';
        */

        // 덱이 비어있는 상태면 그냥 지나가야 한다.
        if (dqs[1].size()) {
            for (int j = 1; j <= n; j++) {
                v.push_back({ dqs[j].front()[0] + t + cost[j][i] - cost[j][dqs[j].front()[1] - 1], j, dqs[j].front()[1] });
            }
            sort(all(v));

            /*/ debug1
            for (int j = 0; j < n; j++) {
                cout << '(' << v[j][0] << ',' << v[j][1] << ')' << ' ';
            }
            cout << '\n';
            */
        }

        for (int j = 1; j <= n; j++) {
            // dp 테이블을 관리
            for (auto [val, cl, pr] : v) {
                if (cl != j && cl != block[j]) {
                    dp[j][i] = {val, i + 1};
                    break;
                }
            }
            
            // 덱에다가 i-s+1번 값을 넣을 수 있다.
            if (dp[j][i - s + 1][1] != -1) {
                while (dqs[j].size() && dqs[j].back()[0] >= dp[j][i - s + 1][0] - cost[j][i - s + 1] + cost[j][dqs[j].back()[1] - 1]) {
                    dqs[j].pop_back();
                }
                dqs[j].push_back(dp[j][i - s + 1]);
            }
            if (dqs[j].front()[1] == i - e + 1) dqs[j].pop_front();
        }
    }

    /*/ debug2
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m + s; j++) {
            cout << '(' << dp[i][j][0] << ',' << dp[i][j][1] << ')' << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */

    pii ans = { (int)1e9, -1 };

    for (int i = 1; i <= n; i++) {
        for(int j = m; j < m + s; j++)
            ans = min(ans, dp[i][j]);
    }

    cout << ans[0]-t;
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

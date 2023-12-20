#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int v, e; cin >> v >> e;

    vector<vector<int>> adj(v + 1);
    vector<int> vst(v + 1);
    vector<int> bccNum(v + 1);
    vector<vector<int>> BCC(1);
    vector<int> isCutPoint(v + 1);

    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int vstCnt = 1, bccCnt = 1;
    vector<int> stk;
    function<int(int, int)> dfs = [&](int here, int par) {
        vst[here] = vstCnt++;
        stk.push_back(here);
        int ret = vst[here];
        int grouped = 0;
        for (int next : adj[here]) {
            int val = vst[next];
            if (!val) {
                val = dfs(next, here);
                if (val == vst[here] || (val == vst[next] && val > vst[here])) {
                    BCC.push_back(vector<int>());
                    while (stk.back() != here) {
                        BCC.back().push_back(stk.back());
                        stk.pop_back();
                    }
                    BCC.back().push_back(here);
                }
            }
            ret = min(ret, val);
        }
        return ret;
    };
    for (int i = 1; i <= v; i++) {
        if(!vst[i])
            dfs(i, 0);
    }
    for (auto bcc : BCC) {
        for (int i : bcc) {
            bccNum[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= v; i++) {
        if (bccNum[i] >= 2) ans++;
    }
    cout << ans << '\n';
    for (int i = 1; i <= v; i++) {
        if (bccNum[i] >= 2) cout << i << ' ';
    }
    
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
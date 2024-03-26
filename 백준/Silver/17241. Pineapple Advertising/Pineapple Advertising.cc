#include<bits/stdc++.h>
#include<unordered_set>
#include<array>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define bs bitset<32>
#define INF 1e9
void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> chk(n + 1);
    vector<int> vst(n + 1);
    while (q--) {
        int x; cin >> x;
        if(vst[x]){
            cout << 0 << '\n';
            continue;
        }
        vst[x] = 1;
        int cnt = 0;
        if (chk[x] == 0) {
            chk[x] = 1;
            cnt++;
        }
        for (int y : adj[x]) {
            if (chk[y] == 0) {
                chk[y] = 1;
                cnt++;
            }
        }
        cout << cnt << '\n';
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
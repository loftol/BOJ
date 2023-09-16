#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

#define all(x) x.begin(),x.end()
#define vi vector<int>
#define mat vector<vi>
#define ll long long
int n;
vi vst, inner;
mat adj;

int dfs(int here) {
    int ret = 0;
    vst[here] = 1;
    for (int next : adj[here]) {
        if (!vst[next]) {
            if (inner[next]) ret++;
            else {
                ret += dfs(next);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    adj = mat(n + 1);
    
    inner = vst = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '1') inner[i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            int cnt = dfs(i) + 1;
            ans += (ll)cnt * (cnt - 1);
        }
    }

    cout << ans;

    return 0;
}

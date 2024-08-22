#include<bits/stdc++.h>
#include<array>
using namespace std;
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define ll long long
void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<pii> arr(n - 1);
    vector<set<int>> vs(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        if (i != n - 2) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vs[u].insert(v);
        vs[v].insert(u);
        arr[i] = { u, v };
    }
    if (n == 3) {
        cout << -1 << '\n';
        return;
    }
    auto [uu, vv] = arr.back();
    vector<int> dep(n + 1), root(n + 1);

    // dfs 정의
    function<void(int, int, int)> dfs = [&](int here, int pre, int rt) {
        root[here] = rt;
        for (int next : adj[here]) {
            if (next == pre) continue;
            dep[next] = dep[here] + 1;
            dfs(next, here, rt);
        }
        };
    dfs(uu, 0, uu);
    dfs(vv, 0, vv);
    int xy = uu ^ vv;
    vector<vector<int>> adj2(n + 1);
    vector<pii> ans;
    for (int i = 0; i < n - 2; i++) {
        auto [u, v] = arr[i];
        if (dep[u] < dep[v]) {
            adj2[v].push_back(xy ^ root[v]);
            adj2[xy ^ root[v]].push_back(v);
            ans.push_back({ v, xy ^ root[v] });
        }
        else {
            adj2[u].push_back(xy ^ root[u]);
            adj2[xy ^ root[u]].push_back(u);
            ans.push_back({ u, xy ^ root[u] });
        }
    }

    vector<int> uar, var;
    function<void(int, int, int)> dfs2 = [&](int here, int pre, int rt) {
        root[here] = rt;
        uar.push_back(here);
        for (int next : adj2[here]) {
            if (next == pre) continue;
            dep[next] = dep[here] + 1;
            dfs2(next, here, rt);
        }
        };
    function<void(int, int, int)> dfs3 = [&](int here, int pre, int rt) {
        root[here] = rt;
        var.push_back(here);
        for (int next : adj2[here]) {
            if (next == pre) continue;
            dep[next] = dep[here] + 1;
            dfs3(next, here, rt);
        }
        };
    root = vector<int>(n + 1);
    dep = vector<int>(n + 1);
    dfs2(uu, 0, uu);
    dfs3(vv, 0, vv);
    
    //for (int i = 1; i <= n; i++) cout << root[i] << ' ';
    bool flag = false;
    for (int i : uar) {
        for (int j : var) {
            if (root[i] != root[j] && vs[i].find(j) == vs[i].end()) {
                ans.push_back({ i, j });
                flag = true;
                break;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (ans.size() == n - 1) {
        for (auto [uuu, vvv] : ans) {
            cout << uuu << ' ' << vvv << '\n';
        }
    }
    else {
        cout << -1 << '\n';
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
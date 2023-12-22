#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        arr[i] = v;
    }

    vector<int> stk;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (stk.size()) {
            if (stk.back() < arr[i]) break;
            else if(stk.back() > arr[i]) ans++;
            stk.pop_back();
        }
        stk.push_back(arr[i]);
    }
    ans += stk.size();
    cout << ans << '\n';
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
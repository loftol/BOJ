#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>
void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    vector<int> table, vst(n);
    for (int i = 0; i < n; i++) {
        auto iter = lower_bound(all(table), arr[i]);
        int idx = iter - table.begin();
        vst[i] = idx;

        if (idx == table.size()) table.push_back(arr[i]);
        else table[idx] = arr[i];
    }

    int x = table.size();
    cout << x << '\n';
    x--;
    vector<int> ans = { 1000000001 };
    for (int i = n - 1; i >= 0; i--) {
        if (vst[i] == x && arr[i] < ans.back()) {
            ans.push_back(arr[i]);
            x--;
        }
    }
    for (int i = 0; i < table.size(); i++) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
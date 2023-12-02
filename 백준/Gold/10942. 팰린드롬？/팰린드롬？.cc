#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<int> arr(2 * n - 1);
    for (int i = 0; i <= 2 * n - 2; i += 2) cin >> arr[i];
    vector<vector<int>> isPal(n, vector<int>(n));
    for (int i = 0; i <= 2 * n - 2; i++) {
        int l = i, r = i;
        while (l >= 0 && r <= 2 * n - 2 && arr[l] == arr[r]) {
            if (l % 2 == 0) isPal[l / 2][r / 2] = 1;
            l--;r++;
        }
    }

    int m; cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        cout << isPal[u][v] << '\n';
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
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
    vector<int> arr(n); for (int& i : arr)cin >> i;
    vector<int> table;
    for (int i = 0; i < n; i++) {
        auto iter = lower_bound(all(table), arr[i]);
        if (iter != table.end()) {
            table[iter - table.begin()] = arr[i];
        }
        else {
            table.push_back(arr[i]);
        }
    }
    cout << table.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}
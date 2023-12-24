#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define tll array<long long, 3>
#define mat vector<vector<int>>
#define pll array<ll, 2>

int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int l = 0, r = 0;
    vector<int> answers;
    cout << "? 1 " << n << endl;
    cin >> r;
    for (int i = 1; i < n; i++) {
        cout << "? " << i+1 << ' ' << n << endl;
        int a; cin >> a;
        cout << "? " << 1 << ' ' << i << endl;
        int b; cin >> b;
        if (r > a && l < b) answers.push_back(i);
        l = b;
        r = a;
    }
    cout << "? " << 1 << ' ' << n << endl;
    int b;
    cin >> b;
    if (b > l) answers.push_back(n);

    cout << "! " << answers.size() << ' ';
    for (int ans : answers) {
        cout << ans << ' ';
    }
    cout << endl;
    exit(0);
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
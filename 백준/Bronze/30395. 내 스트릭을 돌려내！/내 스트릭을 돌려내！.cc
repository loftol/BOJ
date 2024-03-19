#include<bits/stdc++.h>
#include<array>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<int, 3>
#define tll array<ll, 3>
#define bs bitset<32>
#define INF 1e9
void solve() {
    int n; cin >> n;
    int cnt = 0;
    int Mcnt = 0;
    int freeze = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > 0) cnt++;
        else {
            if (freeze <= i) {
                freeze = i + 2;
            }
            else {
                cnt = 0;
            }
        }
        if (Mcnt < cnt) {
            Mcnt = cnt;
        }
    }
    cout << Mcnt;
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
#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    ll t; cin >> t;
    int n; cin >> n;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i], A[i] += A[i - 1];
    int m; cin >> m;
    vector<ll> B(m + 1);
    for (int i = 1; i <= m; i++) cin >> B[i], B[i] += B[i - 1];

    unordered_map<ll, ll> Asums, Bsums;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll val = A[j] - A[i];
            Asums[val]++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
            ll val = B[j] - B[i];
            Bsums[val]++;
        }
    }
    ll ans = 0;
    for (auto [val, cnt] : Asums) {
        ans += Bsums[t - val] * cnt;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
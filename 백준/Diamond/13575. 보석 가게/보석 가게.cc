#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)1e9+7

void solve() {
    int n, m; cin >> n >> m;

    vector<int> t(n);
    
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(all(t));
    int lb = t[0];
    t.erase(unique(all(t)), t.end());
    n = t.size();
    for (int i = n - 1; i >= 0; i--) t[i] -= t[0];

    vector<pii> table(1000001);
    table[0] = { 1, 0 };

    vector<int> stk;
    for (int i = 0; i <= 1000000; i++) {
        // 이미 m번째 전파된 녀석은 무시
        //cout << i << ' ';
        if (table[i][0] == 0) continue;

        stk.push_back(i);
        if (table[i][1] == m) continue;

        for (int j = 1; j < n; j++) {
            table[i + t[j]][0] = 1;
            int& x = table[i + t[j]][1];
            if (x == 0)
                x = table[i][1] + 1;
            else
                x = min(x, table[i][1] + 1);
        }
    }

    for (int i : stk) cout << i + lb * m << ' ';
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
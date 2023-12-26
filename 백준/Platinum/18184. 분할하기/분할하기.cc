#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n, k; cin >> n >> k;
    int kk = k;
    int msb = 0;
    while (kk) {
        kk >>= 1; msb++;
    }
    int lsb = 0;

    if (msb > n) {
        if (k == (1 << (msb - 1))) {
            cout << "YES\n";
            for (int i = 0; i < (1 << n); i++) {
                cout << i << ' ';
            }
            return;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    
    
    cout << "YES\n";
    
    vector<int> lst;
    int chk = msb;
    while (msb >= lsb) {
        if (k & (1 << chk)) {
            for (int i = 0; i < (1 << (msb - lsb)); i++) {
                lst.push_back((i*2 + 1) << (lsb));
            }
            lsb++;
        }
        else {
            msb--;
        }
        chk--;
    }
    sort(all(lst));
    for (int i : lst) cout << i << ' ';
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
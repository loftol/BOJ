#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define sii array<int, 6>
void solve() {
    int n; cin >> n;
    int x = (int)sqrt(n - 1) + 1;
    int y = n / x + (n % x ? 1 : 0);
    cout << (x + y) * 2 << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
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
    ll n; cin >> n;
    string str = to_string(n);
    vector<ll> arr(10);
    reverse(all(str));
    ll ten = 1;
    int m = str.size();
    arr[str[0] - '0']++;
    for (int i = 0; i < m; i++) {
        int v = str[i] - '0';
        for (int j = i + 1; j < m; j++) {
            arr[str[j] - '0'] += (i == 0?  v + 1 : v) * ten;
        }
        for (int j = 0; j < v; j++) {
            arr[j] += ten;
        }
        for (int j = 0; j <= 9; j++) {
            arr[j] += v * (ten / 10) * i;
        }
        arr[0] -= ten;
        ten *= 10;
    }
    

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
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
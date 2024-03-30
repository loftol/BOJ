#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define bs bitset<32>
#define TB (*table)
int N, K, arr[1005];

void solve() {

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        if (ch == 'R') arr[i] = 1;
    }

    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (cur != arr[i]) K--;
        else cur ^= 1;
    }
    K = max(K, 0);
    cout << K;

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
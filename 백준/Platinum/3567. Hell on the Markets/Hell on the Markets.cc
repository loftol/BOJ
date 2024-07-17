#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define MAX (int)1e8
#define ll long long
#define tii array<int, 3>
#define pll array<ll, 2>
#define MOD (ll)1e9 + 7
#define MB 4
void solve(int t) {
    int n; cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    ll total = 0;
    for (int i : arr) total += i;
    if (total % 2) {
        cout << "No\n";
        return;
    }

    total /= 2;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (total >= arr[i]) {
            ans[i] = 1;
            total -= arr[i];
        }
    }

    if (total == 0) {
        cout << "Yes\n";
        for (int i : ans) cout << i << ' ';
    }
    else {
        cout << "No\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    for (int i = 0; i < t; i++)
        solve(i);
}
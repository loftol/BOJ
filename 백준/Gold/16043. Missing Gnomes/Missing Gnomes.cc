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
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    queue<int> q;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        arr[x] = 1;
        q.push(x);
    }
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (arr[j]) j++;
        if (q.empty() || j < q.front()) {
            cout << j << '\n';
            j++;
        }
        else {
            cout << q.front() << '\n';
            q.pop();
        }
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
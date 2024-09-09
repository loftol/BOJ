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


void solve() {
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    ll start = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            start += arr[i];
            arr[i] *= -1;
        }
        else break;
    }
    sort(all(arr));
    bool zchk = false;
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({start, -1});
    
    while (k && pq.size()) {
        auto [here, idx] = pq.top();
        pq.pop();
        if (!zchk && !here) {
            zchk = true;
        }
        else {
            cout << here << '\n';
            k--;
        }

        if (idx == n - 1) continue;
        if (idx != -1) {
            pq.push({ here - arr[idx] + arr[idx + 1], idx + 1});
        }
        pq.push({ here + arr[idx + 1], idx + 1 });
    }
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
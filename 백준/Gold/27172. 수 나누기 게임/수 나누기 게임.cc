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
    vector<int> arr;
    vector<int> exist(1000001);
    vector<int> table(1000001);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        exist[a] = 1;
        arr.push_back(a);
    }

    for (int i : arr) {
        for (int j = i * 2; j <= 1000000; j += i) {
            if (!exist[j]) continue;
            table[i]++;
            table[j]--;
        }
    }

    for (int i : arr) {
        cout << table[i] << ' ';
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
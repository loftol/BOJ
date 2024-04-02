#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tll array<ll, 3>
#define bs bitset<32>
#define TB (*table)
#define MAX (int)1e9

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string ret(m, ' ');
    auto chk1 = [&](char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    };
    while (s.size() && chk1(s.back())) {
        s.pop_back();
    }
    if (s.empty()) {
        cout << "NO";
        return;
    }
    ret.back() = s.back();
    int cnt = 0;
    while (s.size() && cnt < 2) {
        if (s.back() == 'A') cnt++;
        s.pop_back();
    }
    ret[m - 2] = ret[m - 3] = 'A';
    if (s.empty()) {
        cout << "NO";
        return;
    }
    for (int i = m - 4; i >= 0; i--) {
        ret[i] = s.back();
        s.pop_back();
        if (s.empty()) break;
    }
    for (char c : ret) {
        if (c == ' ') {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    cout << ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;// cin >> t;
    while (t--) solve();
}
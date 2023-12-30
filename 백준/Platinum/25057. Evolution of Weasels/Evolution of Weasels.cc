#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    string u, v; cin >> u >> v;
    vector<char> stk1, stk2;
    int bcnt1 = 0, bcnt2 = 0;
    for (char c : u) {
        if (c == 'B') bcnt1 ^= 1;
        else {
            if (stk1.size() && stk1.back() == c) {
                stk1.pop_back();
            }
            else {
                stk1.push_back(c);
            }
        }
    }
    for (char c : v) {
        if (c == 'B') bcnt2 ^= 1;
        else {
            if (stk2.size() && stk2.back() == c) {
                stk2.pop_back();
            }
            else {
                stk2.push_back(c);
            }
        }
    }
    if (bcnt1 == bcnt2 && stk1 == stk2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; cin >> t;
    while (t--) solve();
}
#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 1e9 + 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>
#define fii array<int, 4>

void solve() {
    unordered_map<int, tii> mp;
    string str; cin >> str;
    int n = str.size();
    vector<int> table(n + 1);
    mp[0] = { 1, 1, 1 };
    for (int i = 0; i < n; i++) {
        if (str[i] == 'S') {
            table[i + 1] = table[i] + 2;
        }
        else if(str[i] == 'K') {
            table[i + 1] = table[i] - 1;
        }
        else {
            table[i + 1] = table[i];
        }
        if (mp.find(table[i + 1]) == mp.end())
            mp[table[i + 1]] = { i + 2, i + 2, 0 };
        else {
            mp[table[i + 1]][1] = i + 1;
        }
        if (str[i] == 'S' || str[i] == 'K') {
            mp[table[i]][2] += 1;
            mp[table[i + 1]][2] += 1;
        }
    }

    int M = -1;
    
    for (auto [val, pi] : mp) {
        auto [u, v, w] = pi;
        if (w >= 3) M = max(M, v - u + 1);
    }
    
    cout << M;
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
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

void solve() {
    cout << "? abcdefghijklmnopqrstuvwxyz" << endl;
    string str;
    getline(cin, str);
    istringstream ss(str);
    int u;
    int n = 0;
    while (ss >> u) n = max(u, n);

    vector<int> arr(n);

    for (int i = 0; i < 5; i++) {
        vector<char> queries;
        for (int j = 0; j < 26; j++) {
            if ((1 << i) & j) {
                queries.push_back('a' + j);
            }
        }

        cout << "? ";
        for (char c : queries) cout << c;
        cout << endl;

        int m;
        cin >> m;
        for(int x = 0; x < m; x++) {
            cin >> u;
            arr[u - 1] += (1 << i);
        }
    }
    string res(n, 'a');
    for (int i = 0; i < n; i++)
        res[i] += arr[i];
    cout << "! " << res << endl;
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
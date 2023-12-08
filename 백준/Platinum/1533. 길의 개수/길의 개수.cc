#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define pii array<int, 2>
#define tii array<int, 3>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
#define mat vector<vector<ll>>

using namespace std;

void solve() {
    int n, s, e, t; cin >> n >> s >> e >> t;
    s--, e--;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int mod = 1'000'003;
    
    vector<mat> rawRoute(6, mat(n, vector<ll>(n)));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (board[i][j] != '0') rawRoute[board[i][j] - '0'][i][j] = 1;
    for (int i = 0; i < n; i++)
        rawRoute[0][i][i] = 1;

    auto matAdd = [&](const mat& a, const mat& b) {
        mat ret = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] += b[i][j];
                ret[i][j] %= mod;
            }
        }
        return ret;
    };
    
    auto matProd = [&](const mat& a, const mat& b) {
        mat ret = mat(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret[i][j] += a[i][k] * b[k][j];
                    ret[i][j] %= mod;
                }
            }
        }
        return ret;
    };

    unordered_map<int, mat> mats;

    function<mat(int)> dnc = [&](int x) {
        if (mats.find(x) != mats.end()) return mats[x];
        if (x == 1) return rawRoute[1];
        if (x == 0) return rawRoute[0];
        int mid = x / 2;
        mats[x] = matProd(dnc(mid), dnc(x - mid));
        
        
        //cout << x << '\n';
        //cout << mid << ' ' << x - mid << '\n';
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j < i; j++) {
                if (mid - j < 0 || mid - j + i > x) continue;
                mats[x] = matAdd(mats[x], matProd(matProd(dnc(mid - j), rawRoute[i]), dnc(x - (mid - j + i))));
                //cout << '\n' << mid - j << ' ' << i << ' ' << x - mid + j - i;
            }
            //cout << '\n';
        }
        //cout << '\n';
        return mats[x];
    };

    cout << dnc(t)[s][e];

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while(t--) solve();
    
    return 0;
}
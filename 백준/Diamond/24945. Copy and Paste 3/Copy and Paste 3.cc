#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD 998244353

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll a, b, c; cin >> a >> b >> c;
    vector<vector<int>> nxt(n + 1, vector<int>(n + 1, n + 1));
    map<ll, int> mp;

    function<vector<int>(string)> makez = [](string str) {
        int n = str.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && str[r - l] == str[r]) r++;
                z[i] = r - l; r--;
            }
            else {
                int k = i - l;
                if (z[k] < r - i + 1) z[i] = z[k];
                else {
                    l = i;
                    while (r < n && str[r - l] == str[r]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    };

    for (int u = 0; u < n; u++) {
        vector<int> z(n);
        vector<int> tmp = makez(string(s.begin() + u, s.end()));
        
        for (int i = 0; i < tmp.size(); i++) {
            z[i + u] = tmp[i];
        }
        int l = 1, r = 1;

        for (; r < n - u; r++) {
            while (z[u + r] >= l && l <= r) {
                nxt[u][u + l] = u + r;
                l++;
            }
        }
    }
    // dp[i][i+1] = A + B, dp[i][i] = 0 초기화 (반열린구간으로 관리하니까)
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, MAX));
    for (int i = 0; i < n; i++) {
        dp[i][i + 1] = a + b;
        dp[i][i] = 0;
    }

    // l = 2 ~ n까지로 해서 dp[i][i+l]의 값들을 각각 계산해준다. 이때 해야되는 첫번째는
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            if (l > 1) {
                // dp[i][i+l] = min(dp[i][i+l-1], dp[i+1][i+l] + A, dp[i][i+l] + A)은 매번 해줘야 하고,
                dp[i][i + l] = min({ dp[i][i + l], dp[i + 1][i + l] + a, dp[i][i + l - 1] + a });
                // x = i + l에서 시작해서 x = a[i][x]를 해가면서 슬라이딩을 하면서 범위가 겹치지 않으면
            }
            int x = i;
            int j = x + l;
            int ccnt = 1;
            for (; x <= n - l; x = nxt[x][x + l]) {
                if (j > x) continue;
                // dp[i][x]를 갱신해준다. 이때 갱신해주는건 A연산을 몇번해야하는지 C연산을 몇번해야하는지로 해서 적당히 계산하면 된다.
                // dp값은 다 치고 B연산을 한 직후까지의 cost로 하면 적당히 계산 가능
                ccnt++;
                dp[i][x+l] = min(dp[i][x+l], dp[i][i+l] + ccnt * c + (x + l - i - l * ccnt) * a + b);
                j = x + l;
            }
        }
    }
    cout << dp[0][n] - b;
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
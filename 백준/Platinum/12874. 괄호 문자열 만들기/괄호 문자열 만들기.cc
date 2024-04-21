#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)1e18
#define MOD (ll)1e9+7

void solve() {
    string str; cin >> str;
    str = ' ' + str;

    int n = str.size();
    vector<vector<ll>> dp(n+1, vector<ll>(n + 1, -1));

    // 내 오른쪽의 첫번째 '('와')'의 위치를 구해야함.
    vector<pii> brackets(n);
    pii bracket = { -1,  -1 };
    for (int i = n - 1; i >= 0; i--) {
        brackets[i] = bracket;
        if (str[i] == '(') bracket[0] = i;
        else bracket[1] = i;
    }
    
    function<ll(int, int)> dfs = [&](int here, int remain) {
        ll& ret = dp[here][remain];
        if (ret != -1) return ret;
        // '('의 남은 개수가 음수가 되지 않는 선에서 모든 경우를 봐야함
        ret = 0;
        if (str[here] == '(') remain++;
        else if (str[here] == ')') remain--;
        if (remain == 0 && here != 0) ret++;
        if (remain > 0 && brackets[here][1] != -1) {
            ret += dfs(brackets[here][1], remain);
        }
        if(brackets[here][0] != -1)
            ret += dfs(brackets[here][0], remain);
        ret %= MOD;
        return ret;
        };

    cout << dfs(0, 0);
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
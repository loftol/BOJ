#include<bits/stdc++.h>
#include<array>
#include<bit>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define pll array<ll, 2>
#define tii array<ll, 3>
#define MAX (ll)6e18
#define MOD 998244353

// 여기서는 3^n도 못 써서 n*2^n짜리 SOS를 써서 전처리를 해둬야 함

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (int& i : a) cin >> i;
    vector<int> b(m); for (int& i : b) cin >> i;

    // SOS 적용 부분
    vector<int> f(1 << m);
    for (int j = 0; j < m; j++) for (int i = 0; i < (1 << m); i++) if (i & (1 << j)) f[i] += b[j];
    //for (int i : f) cout << i << ' ';
    //cout << '\n';
    // 값 -> bitset mapping
    vector<vector<int>> vb(1001);
    for (int i = 0; i < (1 << m); i++) if(f[i] <= 1000) vb[f[i]].push_back(i);

    // 같은 데를 한번 더 방문하는 게 불가능하므로 그냥 bfs를 뛰면 된다.
    vector<int> vst(1 << m);
    queue<int> q;
    q.push(0);
    for (int i = 0; i < n; i++) {
        queue<int> nextq;
        while (q.size()) {
            int here = q.front();
            //cout << here << '\n';
            q.pop();
            for (int next : vb[a[i]]) {
                if (!(next & here) && !vst[next | here]) {
                    vst[next | here] = 1;
                    nextq.push(next | here);
                }
            }
        }
        if (nextq.size() == 0) {
            cout << "NO";
            return;
        }
        q = nextq;
    }
    cout << "YES";
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
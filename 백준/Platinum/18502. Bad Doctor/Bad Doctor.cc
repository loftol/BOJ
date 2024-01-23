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
    int n, m; cin >> n >> m;
    vector<ll> cost(m + 1); 
    for (int i = 1; i <= m; i++) cin >> cost[i];
    vector<tii> docInfo(n);
    vector<vector<int>> docList(n);
    for (int i = 0; i < n; i++) {
        int l, r, k; cin >> l >> r >> k;
        docInfo[i] = { l, r + 1, i }; // [l,r)
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            docList[i].push_back(x);
        }
    }

    sort(all(docInfo));

    vector<tii> mxlr(m + 1, {-1, -1, -1});
    vector<ll> docSum(n);
    ll total = 0;

    for (auto [l, r, i] : docInfo) {
        for (int j : docList[i]) {
            auto& [mxl, mxr, u] = mxlr[j];
            if (l < mxr) {
                mxl = max(l, mxl);
                if (r < mxr) {
                    docSum[u] -= cost[j] * max(0, (r - mxl));
                    mxl = max(mxl, r);
                }
                else {
                    docSum[u] -= cost[j] * max(0, (mxr - mxl));
                    mxl = mxr;
                    mxr = r;
                    u = i;
                    docSum[i] += cost[j] * (mxr - mxl);
                    total += cost[j] * (mxr - mxl);
                }
            }
            else {
                docSum[i] += cost[j] * (r - l);
                mxl = l;
                mxr = r;
                u = i;
                total += cost[j] * (r - l);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << total - docSum[i] << ' ';
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
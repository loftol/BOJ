#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
using namespace std;

ll op(pii a, pii b) {
    return (ll)a[0] * b[1] - (ll)a[1] * b[0];
}

int ccw(pii o, pii a, pii b) {
    pii u = { a[0] - o[0], a[1] - o[1] };
    pii v = { b[0] - o[0], b[1] - o[1] };
    ll outp = op(u, v);
    if (!outp) return outp;
    return outp / abs(outp);
}

void solve() {
    int n; cin >> n;
    vector<array<pii, 2>> segs(n);
    for (int i = 0; i < n; i++) {
        auto& [a, b] = segs[i];
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        if (a > b) swap(a, b);
    }

    sort(all(segs));

    vector<int> par(n);
    iota(all(par), 0);
    vector<int> cnt(n, 1);

    function<int(int)> find = [&](int a) {
        if (par[a] != a) return par[a] = find(par[a]);
        return a;
    };

    function<bool(int, int)> uni = [&](int a, int b) {
        if (find(a) != find(b)) {
            cnt[par[a]] += cnt[par[b]];
            par[par[b]] = par[a];
            return true;
        }
        return false;
    };

    function<bool(int, int)> isCross = [&](int a, int b) {
        if (a > b) swap(a, b);
        auto [a1, a2] = segs[a];
        auto [b1, b2] = segs[b];
        int ccw1 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
        int ccw2 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
        if (ccw1 == 0 && ccw2 == 0) {
            if (a2 >= b1) return true;
            else return false;
        }
        else if (ccw1 <= 0 && ccw2 <= 0) return true;
        else return false;
    };

    int num = n;
    int maxSize = 1;
    for (int a = 0; a < n; a++)
        for (int b = a + 1; b < n; b++)
            if (isCross(a, b) && uni(a, b)) {
                num--;
                maxSize = max(maxSize, cnt[find(a)]);
            }
       
    cout << num << '\n' << maxSize;


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
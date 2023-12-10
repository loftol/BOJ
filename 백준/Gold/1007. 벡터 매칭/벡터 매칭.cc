#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long
#define INT ll
#define vi vector<INT>
#define pii pair<ll,ll>
#define MOD 1000000000
#define D 1000000000

using namespace std;

int n, t;
vector<pii> vecs;

double minLength(int depth, int cnt, pii vec) {
    double val = D;
    if (abs(cnt) > (n - depth)) return val;
    if (depth == n) {
        if (cnt == 0)
            val = sqrt((double)(vec.first * vec.first + vec.second * vec.second));
    }
    else {
        val = minLength(depth + 1, cnt - 1, { vec.first + vecs[depth].first * cnt, vec.second + vecs[depth].second * cnt });
        val = min(val, minLength(depth + 1, cnt + 1, { vec.first + vecs[depth].first * cnt, vec.second + vecs[depth].second * cnt }));
    }
    return val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        vecs = vector<pii>(n);
        pii prev, next;
        vecs[0] = { 0,0 };
        cin >> prev.first >> prev.second;
        for (int i = 1; i < n; i++) {
            cin >> next.first >> next.second;
            vecs[i] = { next.first - prev.first, next.second - prev.second };
            swap(prev, next);
        }
        double ans = minLength(0, 0, { 0,0 });
        cout << fixed;
        cout.precision(8);
        cout << ans << '\n';
    }

    return 0;
}
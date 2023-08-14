#include <bits/stdc++.h>
#include <array>

#define INF 2000000000
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

vector<int> par;
vector<ll> psum;
int find(int a) {
    if (par[a] != a) return par[a] = find(par[a]);
    return a;
}

bool uni(int a, int b) {
    if (par[a] == -1 || par[b] == -1) return false;
    if ((a = find(a)) != (b = find(b))) {
        par[b] = a;
        psum[a] += psum[b];
        return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int& i : A) cin >> i;
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b) {
        if (A[a] == A[b]) return a < b;
        return A[a] > A[b];
        });

    par = vector<int>(n, -1);
    psum = vector<ll>(n);

    ll M = 0;

    for (int i : idx) {
        par[i] = i;
        psum[i] = 1;
        if (i > 0) uni(i, i - 1);
        if (i < n - 1) uni(i, i + 1);
        M = max(M, psum[i] * A[i]);
    }

    cout << M;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tc = 1; //cin >> tc;
    while (tc--) solve();


    return 0;
}
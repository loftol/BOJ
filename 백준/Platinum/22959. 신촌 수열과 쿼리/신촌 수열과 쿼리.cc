#include <bits/stdc++.h>
#include <array>

#define ll long long int
#define ld long double
#define mat vector<vector<int>>
#define vi vector<int>
#define pii array<int, 2>
#define all(v) v.begin(),v.end()

using namespace std;
int S = 1, N, M;
int lo = -1, hi = -1;
vector<int> min_seg;
vector<ll> sum_seg;

void update(int idx, ll val) {
    idx += S;
    sum_seg[idx] = val;
    min_seg[idx] = val;
    while(idx /= 2){
        sum_seg[idx] = sum_seg[2 * idx] + sum_seg[2 * idx + 1];
        min_seg[idx] = min(min_seg[2 * idx], min_seg[2 * idx + 1]);
    }
}

void init() {
    while (S < N) S <<= 1;
    sum_seg = vector<ll>(2 * S);
    min_seg = vector<int>(2 * S, 1'000'000'001);
    for (int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        update(i, inp);
    }
}

ll getSum(int l, int r, int b, int e, int idx) {
    if (b >= l && e <= r) return sum_seg[idx];
    if (l >= e || r <= b) return 0;
    int mid = (b + e) / 2;
    return getSum(l, r, b, mid, idx * 2) + getSum(l, r, mid, e, idx * 2 + 1);
}

void query(int i, int j, int b, int e, int idx) {
    if (idx >= S) {
        if (b > i) hi = e;
        else lo = b;
        return;
    }
    int mid = (b + e) / 2;
    if (min_seg[idx] >= j) return;
    if (i < mid) {
        if (min_seg[2 * idx] < j)
            query(i, j, b, mid, 2 * idx);
        if (hi == S + 1 && min_seg[2 * idx + 1] < j)
            query(i, j, mid, e, 2 * idx + 1);
    }
    else {
        if (min_seg[2 * idx + 1] < j)
            query(i, j, mid, e, 2 * idx + 1);
        if (lo == -1 && min_seg[2 * idx] < j)
            query(i, j, b, mid, 2 * idx);
    }
}

void solve() {
    cin >> N;
    init();
    cin >> M;
    while (M--) {
        int q, i, j;
        cin >> q >> i >> j;
        if (q == 1) update(i - 1, j); // b가 one_base이므로
        else {
            lo = -1;
            hi = S + 1;
            query(i - 1, j, 0, S, 1);
            cout << getSum(lo + 1, hi - 1, 0, S, 1) << '\n';
        }
    }
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	//cin >> tc;
	while (tc--) solve();
	return 0;
}
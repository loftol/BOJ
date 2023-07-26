#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vp vector<pii>
#define qt tuple<char, int, int>
#define vq vector<qt>
#define mat vector<vi>

int n, q, timing, S = 1;
vi inTime, outTime, seg, par, val, depth;
mat adj, fastPar;
vq query;



void dfs(int here, int prev) {
    inTime[here] = timing;
    seg[S / 2 + timing] = val[here];
    timing++;

    fastPar[0][here] = prev;
    depth[here] = depth[prev] + 1;
    for (int lvl = 1; lvl < 16; lvl++) {
        fastPar[lvl][here] = fastPar[lvl - 1][fastPar[lvl - 1][here]];
    }

    for (int next : adj[here]) {
        if (inTime[next] == -1)
            dfs(next, here);
    }

    outTime[here] = timing;
    seg[S / 2 + timing] = -val[here];
    timing++;
}

void makeSeg() {
    int N = 2 * n;
    while (S < N) S <<= 1;
    S <<= 1;
    seg = vi(S);
    depth = vi(n + 1);
    for (int idx = 1; idx <= n; idx++) {
        if (inTime[idx] == -1) {
            depth[idx] = 0;
            dfs(idx, idx); // 여기서 prev는 재방문 방지가 아닌 fastPar 초기화용
        }
    }

    for (int SS = S >> 2; SS > 0; SS >>= 1) {
        for (int i = 0; i < SS; i++) {
            int idx = SS + i;
            seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
        }
    }
}

void update(int pos, int val) {
    int idx = S / 2 + pos;
    seg[idx] = val;

    for (idx /= 2; idx > 0; idx /= 2) {
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }
}

int getSum(int l, int r, int b, int e, int idx) {
    if (e <= l || b >= r) return 0;
    if (b >= l && e <= r) return seg[idx];
    int mid = (b + e) / 2;
    return getSum(l, r, b, mid, idx * 2) + getSum(l, r, mid, e, idx * 2 + 1);
}

int find(int a) {
    if (par[a] != a) return par[a] = find(par[a]);
    return a;
}

bool uni(int a, int b) {
    bool ret;
    if (ret = (find(a) != find(b))) {
        par[par[b]] = par[a];
    }
    return ret;
}

int getLCA(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int ddepth = depth[b] - depth[a];

    int lvl = 0;
    while (ddepth > 0) {
        if (ddepth & 1) b = fastPar[lvl][b];
        ddepth >>= 1;
        lvl++;
    }

    lvl = 15;
    while (a != b) {
        if (fastPar[lvl][a] != fastPar[lvl][b] || lvl == 0) {
            a = fastPar[lvl][a];
            b = fastPar[lvl][b];
        }
        else {
            lvl--;
        }
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    val = par = vi(n + 1);
    iota(all(par), 0);
    adj = mat(n + 1);
    fastPar = mat(16, vi(n + 1));
    inTime = outTime = vi(n + 1, -1);

    for (int i = 1; i <= n; i++) cin >> val[i];

    cin >> q;
    query = vq(q);
    for (int i = 0; i < q; i++) {
        string queryType;
        int a, b;
        cin >> queryType >> a >> b;

        if (queryType == "bridge" && uni(a, b)) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        query[i] = { queryType[0], a, b };
    }

    iota(all(par), 0);

    makeSeg();

    for (int i = 0; i < q; i++) {
        auto [qtype, a, b] = query[i];

        if (qtype == 'b') {
            if (uni(a, b)) cout << "yes\n";
            else cout << "no\n";
        }
        else if (qtype == 'p') {
            update(inTime[a], b);
            update(outTime[a], -b);
            val[a] = b;
        }
        else if (qtype == 'e') {
            if (find(a) != find(b)) cout << "impossible\n";
            else {
                int lca = getLCA(a, b);
                int u = getSum(inTime[lca], inTime[a] + 1, 0, S / 2, 1);
                int v = getSum(inTime[lca], inTime[b] + 1, 0, S / 2, 1);
                cout << u + v - val[lca] << '\n';
            }
        }
    }

    return 0;
}
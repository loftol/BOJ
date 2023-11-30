#include<bits/stdc++.h>
#include<array>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>

void solve() {
    int n; cin >> n;
    vector<int> post(n + 1), in(n + 1), rev_in(n + 1);
    for (int i = 1; i <= n; i++) cin >> in[i], rev_in[in[i]] = i;
    for (int i = 1; i <= n; i++) cin >> post[i];
    function<void(int, int, int, int)> search = [&](int pl, int pr, int il, int ir) {
        if (il > ir) return;
        int root = post[pr];
        cout << root << ' ';
        int rpos = rev_in[root];
        int d = ir - rpos;
        search(pl, pr - d - 1, il, rpos - 1);
        search(pr - d, pr - 1, rpos + 1, ir);
    };

    search(1, n, 1, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include <numeric>

using namespace std;

#define ll long long
#define pii array<int, 3>
#define vi vector<int>
#define mat vector<vi>
#define MAX_D 1e9
#define all(x) x.begin(), x.end()

int n;

priority_queue<pii> pq;
vi par;
int find(int a) {
    if (par[a] != a) return par[a] = find(par[a]);
    return a;
}

bool uni(int a, int b) {
    if (find(a) != find(b)) {
        par[par[b]] = par[a];
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int a;
            cin >> a;
            pq.push({ -a, i, j });
        }
    }

    mat adj(n + 1);
    par = vi(n + 1);
    iota(all(par), 0);
    while (pq.size()) {
        auto [w, a, b] = pq.top();
        pq.pop();
        w *= -1;
        if (uni(a, b)) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << adj[i].size() << ' ';
        sort(all(adj[i]));
        for (int j : adj[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
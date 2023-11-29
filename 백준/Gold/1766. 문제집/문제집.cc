#include<iostream>
#include<string>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
#include<array>
#include<set>
#include<functional>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 2>
#define tii array<int, 3>


void solve() {
    int n, m; cin >> n >> m;
    vector<int> ind(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ind[v]++;
        adj[u].push_back(v);
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) pq.push(-i);
    }
    while (pq.size()) {
        int here = pq.top();
        here *= -1;
        cout << here << ' ';
        pq.pop();
        for (int next : adj[here]) {
            ind[next]--;
            if (!ind[next]) {
                pq.push(-next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
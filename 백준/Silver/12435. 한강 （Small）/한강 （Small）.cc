#include<iostream>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<int>> classes(500000);
    vector<int> divCnt(1000001);
    vector<int> lastB(1000001);

    for (int i = 2; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            if (!lastB[j]) lastB[j] = i;
            divCnt[j]++;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        classes[divCnt[i]].push_back(i);
    }

    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int m, n; cin >> n >> m;

        int u = divCnt[n];
        int y = 0;
        for (int j : classes[u]) {
            if (j == n) break;
            if (lastB[j] >= m && lastB[j] != j) y++;
        }
        cout << "Case #" <<  i + 1 << ": " << y << '\n';
    }

    return 0;
}
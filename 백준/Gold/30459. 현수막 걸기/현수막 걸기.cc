#include<iostream>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, r; cin >> n >> m >> r;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    sort(all(arr));
    vector<int> bases = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bases.push_back(arr[j] - arr[i]);
        }
    }
    sort(all(bases));
    bases.erase(unique(all(bases)), bases.end());
    vector<int> heights(m); for (int& i : heights) cin >> i;
    double MA = 0;
    for (int i : heights) {
        int lb = r * 2 / i;
        int u = upper_bound(all(bases), lb) - bases.begin();
        MA = max(MA, (double)bases[u - 1] * i / 2);
    }
    if (!MA) cout << -1;
    else {
        cout.precision(1);
        cout << fixed;
        cout << MA;
    }
    return 0;
}
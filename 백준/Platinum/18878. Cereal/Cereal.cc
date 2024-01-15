#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pii>
#define lmat vector<vl>
#define mat vector<vi>
#define all(x) x.begin(), x.end()
#define BIG 2'000'000'000'000'000
#define X first
#define Y second
#define parSort(a,b) min(a,b), max(a,b)

mat cows;
vi selected;
vi ans;
int n, m;
int cnt = 0;

void recur(int x) {
    int& i = cows[x][0];
    i = min(i + 1, 3);
    for (; i <= 2; i++) {
        if (selected[cows[x][i]] > x) {
            recur(selected[cows[x][i]]);
            selected[cows[x][i]] = x;
            return;
        }
        else if (selected[cows[x][i]] == -1) {
            cnt++;
            selected[cows[x][i]] = x;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    cows = mat(n, vi(3));
    selected = vi(m + 1, -1);
    ans = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i][1] >> cows[i][2];
    }

    for (int x = n - 1; x >= 0; x--) {
        recur(x);
        ans[x] = cnt;
    }
    
    for (int i : ans) cout << i << '\n';

}
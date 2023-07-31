#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <tuple>

#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define tii tuple<int,int>
#define mat vector<vi>
using namespace std;

//=====================풀이========================//

vector<tii> arr;
vector<int> table;

int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    // 점 받자마자 k개 복사해서 저장해두기

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < k; j += 2) {
            int g = gcd(x, y);
            arr.push_back({ x / g, y / g });
            x += 2 * m;
        }
        x %= m;
        x = 2 * m - x;
        for (int j = 1; j < k; j += 2) {
            int g = gcd(x, y);
            arr.push_back({ x / g, y / g });
            x += 2 * m;
        }
    }

    sort(all(arr));

    arr.push_back({ -1, -1 });

    tii t = { 0,0 };
    int cnt = 0, M = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != t) {
            M = max(M, cnt);
            t = arr[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }

    cout << M;

    return 0;
}
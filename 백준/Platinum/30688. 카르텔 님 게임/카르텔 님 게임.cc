#include<iostream>
#include<string>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
#include<array>
using namespace std;
int INF = 50000000;
#define all(x) x.begin(), x.end()
#define pii array<long long, 2>
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    
    if (1 <= n && n <= k) cout << "A and B win";
    else if (k + 3 <= n && n <= 2 * k + 1) cout << "A and B win";
    else cout << "C win";
    return 0;
}
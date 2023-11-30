#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define tii array<int, 3>
#define pii array<int, 2>
#define all(v) v.begin(), v.end()
#define bs bitset<10>
using namespace std;

void solve() {
    vector<vector<int>> prevTable(5, vector<int>(5, 1e9));
    prevTable[0][0] = 0;
    int a; cin >> a;
    while (a) {
        vector<vector<int>> nextTable(5, vector<int>(5, 1e9));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (prevTable[i][j] == 1e9) continue;
                nextTable[i][a] = min(nextTable[i][a], prevTable[i][j] + 4);
                nextTable[a][j] = min(nextTable[a][j], prevTable[i][j] + 4);
                if (i == a || j == a) 
                    nextTable[i][j] = min(nextTable[i][j], prevTable[i][j] + 1);
                if (i == 0) {
                    nextTable[a][j] = min(nextTable[a][j], prevTable[i][j] + 2);
                }
                if (j == 0) {
                    nextTable[i][a] = min(nextTable[i][a], prevTable[i][j] + 2);
                }
                if (i % 2 != a % 2){
                    nextTable[a][j] = min(nextTable[a][j], prevTable[i][j] + 3);
                }
                if (j % 2 != a % 2) {
                    nextTable[i][a] = min(nextTable[i][a], prevTable[i][j] + 3);
                }
            }
        }
        prevTable = nextTable;
        cin >> a;
    }
    int minVal = 1e9;
    for (vector<int> row : prevTable) {
        for (int val : row) {
            minVal = min(val, minVal);
        }
    }
    cout << minVal;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; //cin >> t;
    while(t--) solve();
    
    return 0;
}
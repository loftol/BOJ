#include<iostream>
#include <string>
#include <vector>
#include <cmath>
#define ll long long
#define INT int
#define vi vector<INT>
using namespace std;

string s;
vi cnt;
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    cnt = vi(10);
    bool pos = false;
    int sum3 = 0;

    for (char c : s) {
        if (c == '0') {
            pos = true;
        }
        cnt[c - '0']++;
        sum3 += (c - '0');
        sum3 %= 3;
    }
    pos = pos && (sum3 == 0);
    
    if (pos) {
        for (int i = 9; i >= 0; i--)
        {
            while (cnt[i]) {
                cout << i;
                cnt[i]--;
            }
        }
    }
    else cout << -1;
    return 0;
}
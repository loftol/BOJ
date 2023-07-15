#include <iostream>

using namespace std;

int cnts[100005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    int total = 0, M = 0;
    while(n--) {
        int a;
        cin >> a;
        total = (total + a) % k;
        M = max(M, ++cnts[total]);
    }
    
    cout << M;

    return 0;
}
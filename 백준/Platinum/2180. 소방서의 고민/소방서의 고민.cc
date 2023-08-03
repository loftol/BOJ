#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define A first
#define B second
#define vp vector<pii> 
#define PI 3.14159265358979323846
#define O {0,0}
#define vi vector<ll>

//==================================================================//
//==================================================================//

bool compare(pii& u, pii& v) {
    return u.B * v.A < v.B * u.A;
}

int n;
vector<pii> fires;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> n;

    fires = vector<pii>();

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) continue;
        fires.push_back({ a,b });
    }

    sort(fires.begin(), fires.end(), compare);

    int t = 0;
    int MOD = 40000;

    for (int i = 0; i < fires.size(); i++) {
        t = (fires[i].A + 1) * t + fires[i].B;
        t %= MOD;
    }

    cout << t;

    return 0;
}
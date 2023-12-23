#include<iostream>
#include<tuple>
#include<random>
#include<cassert>

using namespace std;
#define ll long long
#define tl tuple<ll,ll,ll>

tl eeu(ll a, ll b) { // a > b인 상태로 넣을 것
    ll r0 = a, r1 = b, s0 = 1, s1 = 0, t0 = 0, t1 = 1, q;

    while (true) {
        q = r0 / r1;
        r0 = r0 % r1; swap(r0, r1);
        if (r1 == 0) { 
            if (s1 > 0) {
                s1 -= b;
                t1 += a;
            } 
            return { s1, t1, r0 }; 
        }
        s0 -= s1 * q; swap(s0, s1);
        t0 -= t1 * q; swap(t0, t1);
        t1 %= a;
        s1 %= b;
        assert(s1 * a + t1 * b == r1);
    }
}

int main(){
    int t;
    cin >> t;
    ll a, n;
    for (int i = 0; i < t; i++) {
        cin >> n >> a;
        if (n == 1e9 && a == 1) { cout << "IMPOSSIBLE" << '\n'; continue; }
        if (a == 1) {
            cout << n + 1 << '\n';
            continue;
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        auto [s, t, g] = eeu(n, a);
        assert(s * n + t * a == g && t <= 1000000000);
        if (g != 1) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            cout << t << '\n';
        }
    }
    return 0;
}
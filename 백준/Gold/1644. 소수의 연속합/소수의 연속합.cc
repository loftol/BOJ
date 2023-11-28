#include<iostream>
#include<string>
#include<random>
#include<numeric>
#include<algorithm>
#include<map>
#include <queue>
#include<array>
#include<set>
using namespace std;
int INF = 50000000;
#define ll long long
#define all(x) x.begin(), x.end()
#define pii array<int, 3>



void solve() {
    int n; cin >> n;
    vector<int> sieve(n + 1);
    vector<ll> primes = { 0 };
    for (int i = 2; i <= n; i++) {
        if (sieve[i])continue;
        sieve[i] = i;
        primes.push_back(i);
        if (i > 3000) continue;
        for (int j = i * i; j <= n; j += i) {
            if(!sieve[j]) sieve[j] = i;
        }
    }

    for (int i = 1; i < primes.size(); i++) {
        primes[i] += primes[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < primes.size(); i++) {
        auto iter = lower_bound(all(primes), primes[i] + n);
        if (iter != primes.end() && *iter == primes[i] + n) {
            ans++;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}
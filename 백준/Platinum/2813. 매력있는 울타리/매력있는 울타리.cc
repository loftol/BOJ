#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <numeric>
#include <set>
#include <assert.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define PI 3.14159265358979323846
#define O {0,0}
#define all(v) v.begin(), v.end()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pii> 
#define mat vector<vi>
#define lmat vector<vl>


#define MOD (ll)1'000'000'007

// 인덱스마다 다섯가지 케이스로 나눠서 푼다. (양끝 제외하면 세가지)
// 1. 중간 극소
// 2. 끝점 극소
// 3. 이외의 값
// 4. 끝점 극대
// 5. 중간 극대
// => 이거 결정하는데 O(N)
// 
// 이렇게 해두고 3의 경우 서로 대소관계만 맞춘 상태로 배열해둔 다음에
// 순서대로 값을 부여하면 된다.
// => 정렬에 O(NlogN), 부여하는데 O(N)
// => 총 시간복잡도 : O(NlogN) => 가능
//

vi a, b, c, ans;
int n;
vi lm, lM, em, eM, el;
bool cmp(int i, int j) {
    if (a[i] < a[j]) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> n;
    a = vi(n);
    b = vi(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    sort(all(b));

    c = vi(n);
    iota(all(c), 0);
    sort(all(c), cmp);

    for (int i : c) {
        if (i == 0) {
            if (a[i + 1] > a[i])
                em.push_back(i);
            else
                eM.push_back(i);
        }
        else if (i == n - 1) {
            if (a[i - 1] > a[i])
                em.push_back(i);
            else
                eM.push_back(i);
        }
        else {
            if (a[i + 1] > a[i] && a[i - 1] > a[i])
                lm.push_back(i);
            else if (a[i + 1] < a[i] && a[i - 1] < a[i])
                lM.push_back(i);
            else
                el.push_back(i);
        }
    }

    ans = vi(n);

    int idx = 0;

    for (int i : lm) {
        ans[i] = b[idx];
        idx++;
    }
    for (int i : em) {
        ans[i] = b[idx];
        idx++;
    }
    for (int i : el) {
        ans[i] = b[idx];
        idx++;
    }
    for (int i : eM) {
        ans[i] = b[idx];
        idx++;
    }
    for (int i : lM) {
        ans[i] = b[idx];
        idx++;
    }

    ll sum = 0;

    for (int i = 0; i < n - 1; i++) {
        sum += (ll)(abs(ans[i + 1] - ans[i]));
    }

    cout << sum << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }

    return 0;
}  
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define vl vector<ll>

int q, n;
ll k;

priority_queue<ll> pq;
vl arr;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> q;

	while (q--) {
		cin >> n >> k;
		arr = vl(n);
		pq = priority_queue<ll>();

		ll sum = 0;
		for (ll& num : arr) {
			cin >> num;
			sum += num;
		}
		sort(all(arr));

		int idx = 0;
		int ans = 0;
		while (sum > k) {
			ans++;
			while (idx < n && arr[idx] <= k) {
				pq.push(arr[idx]);
				idx++;
			}
			if (pq.empty()) {
				ans = -1;
				break;
			}

			sum -= pq.top();
			k += pq.top();

			pq.pop();
		}

		cout << ans << '\n';
	}

	return 0;
}
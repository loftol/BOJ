#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define vi vector<ll>
#define pii pair<int,int>
using namespace std;

int N, k, p;
vector<pii> times;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	times = vector<pii>(N);
	
	for (int i = 0; i < N; i++) cin >> times[i].first >> times[i].second;
	
	sort(times.begin(), times.end());

	int ans = 0;

	for (pii time : times) {
		if (pq.size()) {
			int compare = pq.top();
			if (time.first >= compare) {
				pq.pop();
				pq.push(time.second);
			}
			else {
				pq.push(time.second);
				ans = max((int)pq.size(), ans);
			}
		}
		else {
			pq.push(time.second);
			ans = max((int)pq.size(), ans);
		}
	}


	cout << ans;

	return 0;
} 
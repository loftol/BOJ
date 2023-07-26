#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int,int>
using namespace std;

int N, P;
vector<int> cost;
vector<pair<int,pii>> bridge;

vector<int> root;

int find(int a) {
	if (root[a] != a) root[a] = find(root[a]);
	return root[a];
}

void uni(int a, int b) {root[root[b]] = root[a];}

int main() {

	fastio;

	cin >> N >> P;

	cost = vector<int>(N + 1);
	root = vector<int>(N + 1);
	for (int i = 1; i <= N; i++) { 
		cin >> cost[i]; 
		root[i] = i;
	}

	for (int i = 0; i < P; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		w = 2 * w + cost[a] + cost[b];
		bridge.push_back({ w,{a,b} });
	}
	sort(bridge.begin(), bridge.end());

	int ans = 0;

	for (auto br : bridge) {
		int w = br.first;
		int a = br.second.first;
		int b = br.second.second;
		if (find(a) != find(b)) { uni(a, b); ans += w; }
	}

	ans += *min_element(cost.begin() + 1, cost.end());

	cout << ans;

	return 0;
}
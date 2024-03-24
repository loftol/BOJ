#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

vector<vector<int>> adj;
vector<int> vst;
int dfs(int here) {
	int ret = 1;
	vst[here] = 1;
	for (int next : adj[here]) {
		if(!vst[next])
			ret += dfs(next);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	vector<int> mosts;
	int most = 0;

	for (int i = 1; i <= n; i++) {
		vst = vector<int>(n + 1);
		int val = dfs(i);
		if (val > most) {
			most = val;
			mosts = { i };
		}
		else if (val == most) {
			mosts.push_back(i);
		}
	}

	for (int i : mosts) cout << i << ' ';

	return 0;
}
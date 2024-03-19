#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int N, M;
vector<vi> match;
vi sel, C;

bool dfs(int here) {
	for (int next : match[here]) {
		if (C[next]) continue;
		C[next] = 1;

		if (sel[next] == -1 || dfs(sel[next])) {
			sel[next] = here;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	match = vector<vi>(N);
	sel = vi(M + 1, -1);
	
	for (int i = 0; i < N; i++) {
		int S;
		cin >> S;
		match[i] = vi(S);
		for (int j = 0; j < S; j++) cin >> match[i][j];
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		C = vi(M + 1);
		if(dfs(i)) ans++;
	}

	cout << ans;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
#define ull unsigned long long
#define pll pair<ull,ull>
#define plpii pair<ull,pii>
#define ull_max (ull)0 - 1
#define BIG_NUM 1000000009
#define INTM (1 << 16)
#define pii pair<int,int>
#define psi pair<string,int>
#define pipii pair<int, pii>
#define qii queue<pii>
using namespace std;

int N;

int adj[16][16];
int minD[INTM][16];


int dp(int visit, int here)
{
	int& ret = minD[visit][here];
	if (ret != -1) return ret;
	if (visit == (1 << N) - 1)
	{
		if (adj[here][0]) ret = adj[here][0];
		else ret = BIG_NUM;
		return ret;
	}
	ret = BIG_NUM;
	for (int i = 0; i < 16; i++)
		if (adj[here][i] && !(visit & (1 << i))) ret = min(ret, dp((visit | (1 << i)),i) + adj[here][i]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	memset(minD, -1, sizeof(minD));

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];

	cout << dp(1, 0);

	return 0;
}
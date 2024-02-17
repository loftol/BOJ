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
#include <cmath>
#include <fstream>
#include <string>
#define ull_max (ull)0 - 1
#define pii pair<int,int>
#define pipii pair<int, pii>
#define ppiii pair<pii, int>
#define ull unsigned long long
#define BIG_NUM 1000000007
#define MAX_INT 1001
#define MAXN 5000
#define MAXF 3000
#define pqi priority_queue<int, vector<int>, greater<int>>
using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;

	vector<pii> ST;
	for (int i = 0; i < N; i++)
	{
		int T, S;
		cin >> S >> T;
		ST.push_back({ S, T });
	}

	sort(ST.begin(), ST.end());

	pqi pq;

	multiset<int, greater<int>> end_time;
	for (int i = 0; i < ST.size(); i++)
	{
		if (pq.size())
		{
			if (pq.top() <= ST[i].first)
				pq.pop();
		}
		pq.push(ST[i].second);
	}

	cout << pq.size();

	return 0;
}
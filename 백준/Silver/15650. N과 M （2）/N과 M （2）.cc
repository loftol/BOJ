#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#define pii pair<int,int>
#define DST_M 10000000

using namespace std;

int N, M;
vector<vector<int>> answers;
vector<int> seq;

void recul(int max, int m)
{
	if (m == M)
	{
		for (int a : seq)
		{
			cout << a << ' ';
		}
		cout << '\n';
	}
	else if (max == N)
	{
		return;
	}
	else
	{
		for (int i = max; i < N; i++)
		{
			seq[m] = i + 1;
			recul(i + 1, m + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	seq = vector<int>(M, 0);
	recul(0, 0);
	return 0;
}
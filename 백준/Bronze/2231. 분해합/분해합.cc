#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#define pii pair<int,int>


using namespace std;

string N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int end = stoi(N);
	for (int i = 1; i < end; i++)
	{
		string comp = to_string(i);
		int sum = i;
		for (char c : comp)
		{
			sum += c - '0';
		}
		if (sum == end)
		{
			cout << comp;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
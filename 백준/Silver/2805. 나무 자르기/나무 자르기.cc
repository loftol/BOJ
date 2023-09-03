# include<iostream>
# include<vector>
# include<queue>
# include<string>
# include<algorithm>
# include<stack>
# include<set>
# define ll long long
# define INT int
# define pii pair<INT,INT>
# define vi vector<INT>
# define mat vector<vi>
# define MOD 1000000007
# define MAX 1000002

using namespace std;

INT N;
ll M, sum;
vi trees;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	trees = vi(N);

	for (int i = 0; i < N; i++)
		cin >> trees[i];

	sort(trees.begin(), trees.end(), greater<>());
	trees.push_back(0);

	int i;
	for (i = 1; i <= N; i++) {
		sum += (ll)(trees[i - 1] - trees[i]) * i;
		if (sum >= M) break;
	}

	cout << trees[i] + (sum - M) / i;

	return 0;
}
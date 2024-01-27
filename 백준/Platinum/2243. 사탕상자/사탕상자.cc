# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
#define mat vector<vi>
using namespace std;

int n, A, B, C, S = 1;

vector<int> seg;

void makeSeg() {
	while (1'000'000 > S) S <<= 1;
	seg = vi(2 * S);
}

void update(int pos, int val) {
	pos += S;
	seg[pos] += val;
	for (pos /= 2; pos > 0; pos /= 2)
		seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

int findIdx(int sum, int idx, int val) {
	if (idx >= S) { return idx - S; }
	if (sum + seg[2 * idx] >= val) return findIdx(sum, 2 * idx, val);
	return findIdx(sum + seg[2 * idx], 2 * idx + 1, val);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	makeSeg();

	while(n--) {
		cin >> A;
		if (A == 1) {
			cin >> B;
			int idx = findIdx(0, 1, B);
			cout << idx << '\n';
			update(idx, -1);
		}
		else {
			cin >> B >> C;
			update(B, C); 
		}
	}

	return 0;
}

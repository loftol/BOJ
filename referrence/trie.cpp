vector<unordered_map<char, int>> adj(1);
vector<int> cnt(1);
	
int nodeCnt = 1;

vector<string> strs;

for (int i = 0; i < n; i++) {
	string str; cin >> str;
	strs.push_back(str);
	int here = 0;
	for (char c : str) {
		if (adj[here].find(c) == adj[here].end()) {
			adj.push_back(unordered_map<char, int>());
			adj[here][c] = nodeCnt++;
			cnt.push_back(0);
		}
		here = adj[here][c];
	}
  // 저장을 끝에만 하고 싶으면 이렇게 하면 됨
	cnt[here]++; 
}

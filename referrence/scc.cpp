// tarjan 알고리즘 - 위상정렬은 번호 역순임에 주의
int sccCnt = 1, vstCnt = 1;
vector<int> sccID(n + 1), vst(n + 1), stk; // n은 정점 개수
vector<vector<int>> SCC;
function<int(int)> make_scc = [&](int here) {
	if (vst[here]) return vst[here];
	vst[here] = vstCnt++; stk.push_back(here);
	int ret = vst[here];
	for (int next : adj[here]) if (!sccID[next]) ret = min(make_scc(next), ret);
	if (ret == vst[here]) {
		SCC.push_back(vector<int>());
		while (stk.size() && vst[stk.back()] >= vst[here]) {
			sccID[stk.back()] = sccCnt;
			SCC.back().push_back(stk.back());
			stk.pop_back();
		}
		sccCnt++;
	}
	return ret;
};
for(int i = 1; i <= n; i++) if(!vst[i]) make_scc(i);

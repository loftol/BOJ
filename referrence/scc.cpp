vector<int> sccID(n + 1), vst(n + 1), stk, SCC; // n은 정점 개수
function<int(int)> make_scc = [&](int here) {
	if (vst[here]) return vst[here];
	vst[here] = vstCnt++; stk.push_back(here);
	int ret = vst[here];
	for (int next : adj[here]) 
		if (!sccID[next]) ret = min(make_scc(next), ret);
	if (ret == vst[here]) {
		vector<int> scc;
		while (stk.size() && vst[stk.back()] >= vst[here]) {
			sccID[stk.back()] = sccCnt;
			scc.push_back(stk.back());
			stk.pop_back();
		}
		sccCnt++;
		sort(all(scc));
		SCC.push_back(scc);
	}
	return ret;
};

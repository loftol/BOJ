function<int(int, int)> dfs = [&](int here, int par) {
        vst[here] = vstCnt++;
        stk.push_back(here);
        int ret = vst[here];
        int grouped = 0;
        for (int next : adj[here]) {
            int val = vst[next];
            if (!val) {
                val = dfs(next, here);
                if (val == vst[here] || (val == vst[next] && val > vst[here])) {
                    BCC.push_back(vector<int>());
                    while (stk.back() != here) {
                        BCC.back().push_back(stk.back());
                        stk.pop_back();
                    }
                    BCC.back().push_back(here);
                }
            }
            ret = min(ret, val);
        }
        return ret;
    };

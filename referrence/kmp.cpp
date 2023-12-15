string pat;

/******pat 초기화 해주기******/

int m = pat.size();
vector<int> fail(m + 1);
auto make_fail = [&]() {
  	fail = vector<int>(m);
  	for (int i = 1, j = 0; i < m; i++) {
		while (j && pat[i] != pat[j]) j = fail[j];
		if (pat[i] == pat[j]) fail[i + 1] = ++j;
	}
};

// 필요에 따라 offset 부분에 1을 체크해 줄수도 있고?
vector<int> ret;
auto match = [&](string str) {
	for (int i = 0, j = 0; i < n; i++) {
		while (j && str[i] != pat[j]) j = fail[j];
		if (str[i] == pat[j]) j++;
		if (j == m) {
			ret.push_back(i - j + 1);
			j = fail[j];
		}
	}
}

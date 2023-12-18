vector<pii> points(n);
for (auto& [x, y] : points) cin >> x >> y;

// 각정렬
sort(all(points));
sort(points.begin() + 1, points.end(), [&](pii a, pii b) {
	return CCW(points[0], a, b) == 1;
	});

// 컨벡스 헐 만드는 부분
vector<pii> ch = {points[0]};
for (int i = 1; i < points.size(); i++) {
	pii c = points[i];
	while (ch.size() > 2) {
		pii b = ch.back();
		ch.pop_back();
		pii a = ch.back();
		if (CCW(a, b, c) == 1) {
			ch.push_back(b);
			break;
		}
	}
	ch.push_back(c);
}
ch.pop_back();

// 캘리퍼스도 덤으로..
for (int i = 0; i < ch.size(); i++) {
	int ni = (i + 1) % ch.size(), nj = (j + 1) % ch.size();
	pii u = sub(ch[ni], ch[i]);
	pii v = sub(ch[nj], ch[j]);

	while (OP(u, v) >= 0) {
		j = nj;
		nj = (j + 1) % ch.size();
		v = SUB(ch[nj], ch[j]);
	}
	pii w = SUB(ch[j], ch[i]);
}

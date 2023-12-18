vector<pii> points(n);
for (auto& [x, y] : points) cin >> x >> y;

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

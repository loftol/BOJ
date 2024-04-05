tll eeu(ll a, ll b) { 
	if (a == 0) return { b, 1, 0 };
	else {
		auto [g, x, y] = eeu(b % a, a);
		return { g, y, x - b / a * y };
	}
}

// modular inverse -> auto [a_inv, _, _] = eeu(a, MOD);
// 시간복잡도는 실제로 빠른 거듭제곱과 비교했을 때 느리지도 않고,
// 범용성은 더 높다.

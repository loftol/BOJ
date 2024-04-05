#define MOD 998244353

tll eeu(ll a, ll b) { 
	if (a == 0) return { b, 1, 0 };
	else {
		auto [g, x, y] = eeu(b % a, a);
		return { g, y, x - b / a * y };
	}
}

// MOD inverse
auto [_, __, a_inv] = eeu(a, MOD);

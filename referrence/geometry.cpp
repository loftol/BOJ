auto SUB = [&](pii a, pii b) {
	return array{ a[0] - b[0], a[1] - b[1] };
};

auto OP = [&](pii a, pii b) {
	return (ll)a[0] * b[1] - (ll)a[1] * b[0];
};

auto DOT = [&](pii a, pii b) {
	return (ll)a[0] * b[0] + (ll)a[1] * b[1];
};

auto CCW = [&](pii o, pii a, pii b) {
	ll op = OP(SUB(a, o), SUB(b, o));
	if (op) return op / abs(op);
	return op;
};

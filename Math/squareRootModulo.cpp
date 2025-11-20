mt19937 rnd(228);
// solve x^2 = a mod p;
// if p = 4k + 3 --- x = a ^ ((p + 1) / 4)
pair < ll, ll > pw_poly(ll i, ll P, ll a) {
    if (P == 0) {
        return make_pair(1, 0);
    }
    if (P & 1) {
        auto poly = pw_poly(i, P - 1, a);
        ll x1 = sum(mult(poly.second, i), poly.first);
        ll x0 = sum(mult(poly.first, i), mult(poly.second, a));
        return make_pair(x0, x1);
    }
    else {
        auto poly = pw_poly(i, P / 2, a);
        ll x1 = mult(2, mult(poly.first, poly.second));
        ll x0 = sum(mult(poly.first, poly.first), mult(mult(poly.second, poly.second), a));
        return make_pair(x0, x1);
    }
}
ll get_residue(ll x) {
// check not divisible x
    if (x % mod == 0) return 0;
    if (mod == 2) return 1;
    if (pw(x, (mod - 1) / 2) == mod - 1) return -1;
    while (true) {
        ll i = rnd() % mod;
        auto poly = pw_poly(i, (mod - 1) / 2, x);
        poly.first = sub(poly.first, 1);
        if (poly.second == 0) continue;
        ll f = mult(poly.first, pw(poly.second, mod - 2));
        if (mult(f, f) != x) continue;
        return f;
    }
}
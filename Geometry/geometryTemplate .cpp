constexpr ld eps = 1e-9;
bool lt(ld a, ld b) {
    return a + eps < b;
}
bool eq(ld a, ld b) {
    return abs(a - b) < eps;
}
bool le(ld a, ld b) {
    return a < b + eps;
}
struct pt {
    ld x, y;
    bool half() const { return lt(0.0, y) || (eq(0.0, y) && le(0.0, x)); }
    pt operator-(pt r) const {
        return {x - r.x, y - r.y};
    }
    pt operator+(pt r) const {
        return {x + r.x, y + r.y};
    }
    ld norm2() {
        return x * x + y * y;
    }
    ld norm() {
        return sqrt(abs(norm2()));
    }
    ld dist(pt r) {
        return ((*this) - r).norm();
    }
};

struct line {
    ld a, b, c;
    line(ld a_, ld b_, ld c_) : a(a_), b(b_), c(c_) {
    }
    line(const pt &f, const pt &s)
            : a(f.y - s.y), b(s.x - f.x), c(-a * f.x - b * f.y) {}
    ld val(const pt &p) const { return a * p.x + b * p.y + c; }
};

ld operator*(const pt &a, const pt &b) { return a.x * b.x + a.y * b.y; }
ld operator^(const pt &a, const pt &b) { return a.x * b.y - b.x * a.y; }
// Sorts in counter-clockwise order
bool angCmp(const pt &a, const pt &b) {
    bool ah = a.half(), bh = b.half();
    return ah == bh ? lt(b ^ a, 0.0) : ah < bh;
}

optional<pt> intersect(const line &a, const line &b) {
    ld d0 = a.a * b.b - b.a * a.b;
    ld dx = a.c * b.b - b.c * a.b;
    ld dy = a.a * b.c - b.a * a.c;
    return eq(d0, 0.0) ? nullopt : make_optional(pt{-dx / d0, -dy / d0});
}

bool isCw(const pt &a, const pt &b, const pt &c) { return lt((b - a) ^ (c - a), 0.0); }
bool isCcw(const pt &a, const pt &b, const pt &c) { return lt(0.0, (b - a) ^ (c - a)); }
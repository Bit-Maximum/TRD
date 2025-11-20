// Пересечение окружности и прямой, пересечение двух окружностей
struct circle {
    pt o;
    ld r;
};

vector<pt> intersect(circle c, line ln) {
    ln.c += c.o.x * ln.a + c.o.y * ln.b;
    ld aabb = ln.a * ln.a + ln.b * ln.b;
    ld x0 = -ln.a * ln.c / aabb;
    ld y0 = -ln.b * ln.c / aabb;
    ld d = c.r * c.r - ln.c * ln.c / aabb;
    if (lt(d, 0.0)) {
        return {};
    }
    if (eq(d, 0.0)) {
        return {c.o + pt{x0, y0}};
    }
    ld mult = sqrt(d / aabb);
    ld ax = x0 + ln.b * mult;
    ld bx = x0 - ln.b * mult;
    ld ay = y0 - ln.a * mult;
    ld by = y0 + ln.a * mult;
    return {c.o + pt{ax, ay}, c.o + pt{bx, by}};
}

vector<pt> intersect(circle c1, circle c2) {
    pt add = c1.o;
    c2.o = c2.o - add;
    c1.o = c1.o - add;
    if (eq(c2.o.x, 0.0) && eq(c2.o.y, 0.0)) {
        return {};
    }
    line ln(-2 * c2.o.x, -2 * c2.o.y, c2.o * c2.o + c1.r * c1.r - c2.r * c2.r);
    c1.o = c1.o + add;
    ln.c -= ln.a * add.x + ln.b * add.y;
    return intersect(c1, ln);
}
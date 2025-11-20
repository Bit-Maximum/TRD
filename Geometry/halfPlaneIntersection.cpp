ld det(ld a11, ld a12, ld a21, ld a22) {
    return (a11 * a22 - a21 * a12);
}
const ld eps = 1e-10;
struct Plane{
    Point v;
    Point M;
    Plane() {}
    Plane(const Point& f2, const Point& f1) {
        M = f2;
        ld len = sqrt(f1.x * f1.x + f1.y * f1.y);
        v = {f1.x / len, f1.y / len};
    }
    bool contain(const Point& f) const {
        return Gr(v * (f - M), 0.0);
    }
    Point getPoint(const Plane& other) {
        ld D = det(v.x, -other.v.x, v.y, -other.v.y);
        if (Eq(D, 0.0)) return {1e12, 1e12};
        ld alpha = det(other.M.x - M.x, -other.v.x, other.M.y - M.y, -other.v.y) / D;
        Point t{M.x + alpha * v.x, M.y + alpha * v.y};
        return t;
    }
};
int half(const Point& v) {
    if (Gr(v.y, 0.0) || (Eq(v.y, 0.0) && Gr(v.x, 0.0))) return 1;
    return 2;
}
bool cmpPlane(const Plane& a, const Plane& b) {
    if (half(a.v) != half(b.v)) {
        return half(a.v) < half(b.v);
    }
    ld d = a.v * b.v;
    if (!Eq(d, 0.0)) {
        return d > eps;
    }
    return b.contain(a.M);
}
bool eqPlane(const Plane& a, const Plane& b) {
    return Eq(a.v * b.v, 0.0);
}
const int maxN = 500005;
Plane pl[maxN];
Plane res[maxN];
const ld maxC = 2e7;
Point ans[maxN];
int cntPl = 0;
int halfPlaneIntersect() {
    Point box[4];
    box[0] = Point(-maxC, -maxC);
    box[1] = Point(maxC, -maxC);
    box[2] = Point(maxC, maxC);
    box[3] = Point(-maxC, maxC);
    for (int i = 0; i < 4; i++) {
        pl[cntPl++] = Plane(box[i], box[(i + 1) % 4] - box[i]);
    }
    sort(pl, pl + cntPl, cmpPlane);
    cntPl = unique(pl, pl + cntPl, eqPlane) - pl;
    int l = 0;
    int r = 0;
    for (int i = 0; i < cntPl; i++) {
        while (r - l > 1 && !pl[i].contain(res[r - 1].getPoint(res[r - 2]))) {
            r--;
        }
        while (r - l > 1 && !pl[i].contain(res[l].getPoint(res[l + 1]))) {
            l++;
        }
        if (r - l > 0 && (Eq(res[r - 1].v * pl[i].v, 0.0) || Gr(0.0, res[r - 1].v * pl[i].v)))
            return 0;
        if (r - l < 2 || res[l].contain(pl[i].getPoint(res[r - 1]))) {
            res[r++] = pl[i];
        }
    }
    int cntPts = 0;
    for (int i = l; i < r - 1; i++) {
        ans[cntPts++] = res[i].getPoint(res[i + 1]);
    }
    ans[cntPts++] = res[l].getPoint(res[r - 1]);
    return cntPts;
}
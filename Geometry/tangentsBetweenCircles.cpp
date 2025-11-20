ld sqr(ld a) {
    return a * a;
}

void tangents(pt c, ld r1, ld r2, vector<line> &ans) {
    ld r = r2 - r1;
    ld z = sqr(c.x) + sqr(c.y);
    ld d = z - sqr(r);
    if (d < -eps) return;
    d = sqrt(abs(d));
    line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
    ans.push_back(l);
}

vector<line> tangents(circle a, circle b) {
    vector<line> ans;
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2)
            tangents(b.p - a.p, a.r * i, b.r * j, ans);
    for (size_t i = 0; i < ans.size(); ++i)
        ans[i].c -= ans[i].a * a.p.x + ans[i].b * a.p.y;
    return ans;
}
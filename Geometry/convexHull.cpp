int Orientation(pt a, pt b, pt c) {
    ll v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}
bool CW(pt a, pt b, pt c, bool include_collinear) {
    int o = Orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool Collinear(pt a, pt b, pt c) { return Orientation(a, b, c) == 0; }
void ConvexHull(vector<pt> &a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt &a, const pt &b) {
        int o = Orientation(p0, a, b);
        if (o == 0)
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y)
                   < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int) a.size() - 1;
        while (i >= 0 && Collinear(p0, a[i], a.back())) i--;
        reverse(a.begin() + 1 + i, a.end());
    }
    vector<pt> st;
    for (int i = 0; i < (int) a.size(); i++) {
        while (st.size() > 1 && !CW(st[st.size() - 2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }
    a = st;
}
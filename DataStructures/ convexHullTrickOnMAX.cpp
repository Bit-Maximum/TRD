struct ConvexHullLine {
    int64_t a, b;
    inline int64_t f(int64_t x) {
        return a*x + b;
    }
    ConvexHullLine() {
    }
    ConvexHullLine(int64_t a, int64_t b)
            : a(a), b(b) {
    }
};
inline bool operator<(const ConvexHullLine &a, const ConvexHullLine &b) {
    return make_pair(a.a, -a.b) < make_pair(b.a, -b.b);
}
class ConvexHullTrick {
private:
    vector<ConvexHullLine> convexHull;
    inline void add(const ConvexHullLine &ln) {
        while (convexHull.size() > 1) {
            ConvexHullLine
                    _1 = convexHull[convexHull.size() - 2],
                    _2 = convexHull[convexHull.size() - 1],
                    _3 = ln;
            if (
                (_2.a - _1.a) * (_2.b - _3.b) <=
                (_1.b - _2.b) * (_3.a - _2.a)
                ) {
                convexHull.pop_back();
            } else {
                break;
            }
        }
        convexHull.push_back(ln);
    }
public:
    inline int64_t query(int64_t x) {
        int l = 0, r = (int)convexHull.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (convexHull[m].f(x) > convexHull[m+1].f(x)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return convexHull[l].f(x);
    }
    ConvexHullTrick(vector<ConvexHullLine> lines) {
        sort(lines.begin(), lines.end());
        convexHull.clear();
        for (const ConvexHullLine &ln: lines) {
            add(ln);
        }
    }
};

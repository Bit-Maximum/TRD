namespace SufArr {
    /// DONE IN 0-INDEXATION
    ///
    /// n - length of the string s (with added element)
    /// alph - number of different symbols of s ('a' - 'z' and additional separator)
    ///
    /// p[i] - position of i-th sorted element
    /// c[i][j] - unique hash for first (1 << i) elements starting from j-th
    ///
    /// lcp[i] - longest common sequence from p[i] and p[i + 1]
    vector<int> lcp, p;
    const int alph = 27; // alphabet size
    int n;
    // be careful, ADD DELIMITER !!!!
    void Build(const vector<int> &s) {
        n = s.size();
        // phase 0
        p.assign(n, 0);
        vector<int> cnt(alph, 0);
        vector<vector<int>> c(25, vector<int>(n));
        for (int i = 0; i < n; ++i)
            ++cnt[s[i]];
        for (int i = 1; i < alph; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i)
            p[--cnt[s[i]]] = i;
        c[0][p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            if (s[p[i]] != s[p[i - 1]]) ++classes;
            c[0][p[i]] = classes - 1;
        }
        // phase 1
        vector<int> pn(n), cn(n);
        int log_n{0};
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; ++i) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += n;
            }
            cnt.assign(classes, 0);
            for (int i = 0; i < n; ++i)
                ++cnt[c[h][pn[i]]];
            for (int i = 1; i < classes; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                p[--cnt[c[h][pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; ++i) {
                int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
                if (c[h][p[i]] != c[h][p[i - 1]] || c[h][mid1] != c[h][mid2])
                    ++classes;
                cn[p[i]] = classes - 1;
            }
            c[h + 1] = cn;
            log_n = h + 1;
        }
        // lcp
        lcp.resize(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            lcp[i] = 0;
            int ci{p[i]}, cj{p[i + 1]};
            for (int k = log_n; k >= 0; --k)
                if (c[k][ci] == c[k][cj]) {
                    lcp[i] += (1 << k);
                    ci += (1 << k);
                    while (ci >= n) {
                        ci -= n;
                    }
                    cj += (1 << k);
                    while (cj >= n) {
                        cj -= n;
                    }
                }
        }
    }
}

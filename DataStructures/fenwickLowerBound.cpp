int lower_bound(ll lim) {
    int lg = 21;
    int res = 0;
    for (int k = lg; k >= 0; k--) {
        int p = (res + (1 << k));
        if (p <= n && fenw[p] < lim) {
            lim -= fenw[p];
            res += (1 << k);
        }
    }
    return res + 1;
}
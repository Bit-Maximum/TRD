bool find(int x, int *a, int n) {
    int l = 0, r = n + 1; // отрезок поиска полуинтервал: [l, r)
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] >= x)
            l = m;
        else
            r = m;
    }
    return (l < n && a[l] == x);
}
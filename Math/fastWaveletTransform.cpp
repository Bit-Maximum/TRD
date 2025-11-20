int iv2 = (mod + 1) / 2;
void FWT(int *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) % mod, a[i + j + d] = (x - y + mod) % mod;
            }
}
void iFWT(int *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = 1ll * (x + y) * iv2 % mod, a[i + j + d] = 1ll * (x - y + mod) *
                                                                     iv2 % mod;
            }
}
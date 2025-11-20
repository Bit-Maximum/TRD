long long mult(long long a, long long b, long long m) {
    long long q = (long long) ((long double) a * (long double) b / (long double) m);
    long long r = a * b - q * m;
    while (r < 0) r += m;
    while (r >= m) r -= m;
    return r;
}

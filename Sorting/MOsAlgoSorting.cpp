int K = sqrt(N)
int a = 1, b = 0 // create an empty segment
bool isLess(Query a, Query b):
    if a.l / K != b.l / K:
        return a.l < b.l
    return a.r < b.r
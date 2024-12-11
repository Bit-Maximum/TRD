from math import sqrt

INF = 1e10


def dijkstra(n, s, dist):
    d = [INF for _ in range(n)]
    a = [False for _ in range(n)]
    d[0] = s

    for i in range(n):
        v = -1
        for j in range(n):
            if not a[j] and (v == -1 or d[j] < d[v]):
                v = j
        a[v] = True
        for i, p in enumerate(dist[v]):
            d[int(i)] = min(d[i], d[v] + p)

    return d


def distance(p1, p2):
    if p1 == p2:
        return 0.0
    po = (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
    sqr = sqrt(po)
    sqr -= p1[2]
    sqr -= p2[2]
    if sqr < 0:
        return 0.0
    return sqr


if __name__ == '__main__':
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    # (x, y, r)
    edges = [tuple(map(int, input().split())) for i in range(n)]
    edges.append(edges[0])
    edges[0] = (x1, y1, 0)
    edges.append((x2, y2, 0))
    n += 2

    dist = [0] * n
    for i in range(n):
        dist[i] = [0] * n

    for i in range(n):
        for j in range(n):
            dist[i][j] = distance(edges[i], edges[j])

    salamander = dijkstra(n, 0, dist)
    ans = salamander[-1]
    print("{:.10f}".format(ans))

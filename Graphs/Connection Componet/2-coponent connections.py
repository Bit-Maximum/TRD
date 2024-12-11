"""
    Есть N городов. Кроме того, между городами проходят K автомобильных и L железных дорог. i-я автомобильная
дорога в обоих направлениях соединяет p-й и q-й города, а i-я железная дорога в обоих направлениях соединяет r
-й и st-й города. Нет двух дорог, соединяющих одну и ту же пару городов. Аналогично, две железные дороги не соединяют
одну и ту же пару городов.
Мы будем говорить, что города A и B связаны дорогами, если до города B можно добраться из города A, пересекая некоторое
количество дорог. Здесь считается, что любой город связан сам с собой дорогами. Аналогичным образом мы также определим
связь по железным дорогам.
Для каждого города найдите количество городов, соединенных с ним как автомобильными, так и железными дорогами.

Input:
N K K
p1 q1
...
pK qK
r1 s1
...
rL sL
"""

from collections import defaultdict, deque


def find_components(n, graph):
    component = [-1] * (n + 1)
    comp_id = 0

    for start in range(1, n + 1):
        if component[start] == -1:
            queue = deque([start])
            component[start] = comp_id
            while queue:
                node = queue.popleft()
                for neighbor in graph[node]:
                    if component[neighbor] == -1:
                        component[neighbor] = comp_id
                        queue.append(neighbor)
            comp_id += 1

    return component


if __name__ == '__main__':
    N, K, L = map(int, input().split())

    roads_graph = defaultdict(list)
    for i in range(K):
        u, v = map(int, input().split())
        roads_graph[u].append(v)
        roads_graph[v].append(u)

    railways_graph = defaultdict(list)
    for i in range(L):
        u, v = map(int, input().split())
        railways_graph[u].append(v)
        railways_graph[v].append(u)

    road_components = find_components(N, roads_graph)
    railway_components = find_components(N, railways_graph)

    pair_count = defaultdict(int)
    for i in range(1, N + 1):
        pair = (road_components[i], railway_components[i])
        pair_count[pair] += 1

    result = []
    for i in range(1, N + 1):
        pair = (road_components[i], railway_components[i])
        result.append(pair_count[pair])

    print(" ".join(map(str, result)))
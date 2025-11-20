#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define inf INT_MAX

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start, int n) {
    vector<int> distance(n, inf);
    distance[start] = 0;
    // объявим очередь с приоритетами для *минимума* (по умолчанию ищется максимум)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    while (!q.empty()) {
        auto [cur_d, v] = q.top();
        q.pop();
        if (cur_d > distance[v])
            continue;
        for (auto [u, w] : graph[v]) {
            if (distance[u] > distance[v] + w) {
                distance[u] = distance[v] + w;
                q.push({distance[u], u});
            }
        }
    }
    return distance;
}

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

size_t n, m, k;
const long long INF = LONG_LONG_MAX;
struct Edge {
    int from, to, reversed = -1; long long flow, cap, cost;
    Edge(int from, int to, long long int f, long long int cap, long long int cost)
    : from(from), to(to), flow(f), cap(cap), cost(cost) {} 
};
std::vector<std::vector<Edge>> edges; std::vector<long long> d;
std::vector<int> id; std::vector<Edge*> p;

void addEdge(int from, int to, long long flow, long long cap, long long cost) {
    Edge edge = Edge(from, to, flow, cap, cost);
    Edge rev = Edge(to, from, flow, 0, -cost);
    edges[from].push_back(edge);
    edges[to].push_back(rev);
    edges[from].back().reversed = edges[to].size() - 1;
    edges[to].back().reversed = edges[from].size() - 1;
}

long long levitAlgorithm() {
    long long minCost = 0, maxFlow = 0;
    while (true) {
        std::deque<int> q; id.assign(n + 1, 0);
        d.assign(n + 1, INF); p.resize(n + 1);
        d[1] = 0;
        q.push_back(1);
        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            id[u] = 2;
            for (Edge& edge : edges[u]) {
                if (edge.flow < edge.cap && d[edge.to] > d[edge.from] + edge.cost) {
                    d[edge.to] = d[edge.from] + edge.cost;
                    if (!id[edge.to]) { q.push_back(edge.to);} 
                    else if (id[edge.to] == 2) { q.push_front(edge.to);}
                    id[edge.to] = 1;
                    p[edge.to] = &edge;
            } } }
            
        long long del = INF;
        if (d[n] == INF)
            break;
        for (int u = n; u != 1; u = p[u]->from) {
            Edge* edge = p[u];
            del = std::min(del, edge->cap - edge->flow);
        }
        if (maxFlow + del >= k) del = k - maxFlow; // Cut redundant
        for (int u = n; u != 1; u = p[u]->from) {
            Edge* edge = p[u];
            Edge* reversed = &edges[edge->to][edge->reversed];
            edge->flow += del;
            reversed->flow -= del;
            minCost += del * edge->cost;
        }
        maxFlow += del;
        if (maxFlow >= k)
            break;
    }

    if (maxFlow < k) return -1; // Not enough
    return minCost;
}

int main() {
    edges.assign(n + 1, std::vector<Edge>());
    // For all edges...
        addEdge(from, to, 0, cap, cost);
    levitAlgorithm();
}
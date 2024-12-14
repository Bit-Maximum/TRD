#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

constexpr int MAXINT = 1e9;
class DinitzFlow {
private:
    struct Edge {
        int from, to, cap, flow;
        Edge(int from, int to, int cap, int flow)
            : from(from), to(to), cap(cap), flow(flow) {}
    };
    int n, source, sink;
    vector<Edge> edges;             vector<vector<int> > graph;
    vector<int> layer;              vector<int> next;
    inline bool bfs() {
        layer.assign(n, -1);        queue<int> q;
        layer[source] = 0;          q.push(source);
        while (!q.empty() && layer[sink] < 0) {
            int node = q.front();   q.pop();
            for (int edge : graph[node]) {
                int to = edges[edge].to;
                if (edges[edge].cap > edges[edge].flow && layer[to] < 0) {
                    layer[to] = layer[node] + 1;
                    q.push(to);
                }  }  }
        return layer[sink] >= 0;
    }
    int dfs(int node, int flow = MAXINT) {
        if (node == sink) {
            return flow;
        }
        if (flow == 0) {
            return 0;
        }
        for (; next[node] < (int)graph[node].size(); next[node]++) {
            int edge = graph[node][next[node]];
            int to = edges[edge].to;
            if (layer[to] == layer[node] + 1) {
                int pushed = dfs(to, min(flow, edges[edge].cap - edges[edge].flow));
                if (pushed > 0) {
                    edges[edge].flow += pushed;
                    edges[edge ^ 1].flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
public:
    inline void changeSrcDst(int newSource, int newSink) {
        source = newSource; sink = newSink;
        for (Edge& e : edges) {
            e.flow = 0;
        }
    }
    inline const vector<Edge>& getEdges() const {
        return edges;
    }
    inline vector<char> getCut() {
        // side[i] = 1, если в вершину i можно отправить поток
        // side[i] = 0, если вершина i стала недостижимой
        vector<char> side(n, 0);
        function<void(int)> cut = [&](int v) {
            if (side[v]) {
                return;
            }
            side[v] = 1;
            for (int eid : graph[v]) {
                if (edges[eid].cap == edges[eid].flow) {
                    continue;
                }
                cut(edges[eid].to);
            }
            };
        cut(source);
        return side;
    }
    inline int flow() {
        int ans = 0;
        while (bfs()) {
            next.assign(n, 0);
            int pushed = dfs(source);
            while (pushed != 0) {
                ans += pushed;
                pushed = dfs(source);
            }
        }
        return ans;
    }
    inline void addEdge(int from, int to, int cap) {
        graph[from].push_back(edges.size());
        edges.emplace_back(from, to, cap, 0);
        graph[to].push_back(edges.size());
        edges.emplace_back(to, from, 0, 0);
    }
    DinitzFlow(int n, int source, int sink)
        : n(n), source(source), sink(sink), graph(n), layer(n), next(n) {
    }
};

int main()
{
    int n, s, t;
    n = 3;
    s = 1;
    t = 2;
    DinitzFlow solver = DinitzFlow(n, s, t);
    // Source edges
    solver.addEdge(s, 0, 5);
    // Middle edges
    solver.addEdge(0, 3, 10);
    // Sink edges
    solver.addEdge(3, t, 5);
    cout << "Maximum flow: " << solver.flow();
    /*auto res = solver.getEdges();
    for (auto r : res) {
        cout << r.from << ' ' << r.to << ' ' << r.cap << ' ' << r.flow << '\n';
    }*/

    auto vec = solver.getCut();
    for (auto c : vec) {
        cout << c << ' ';
    }

    return 0;
}

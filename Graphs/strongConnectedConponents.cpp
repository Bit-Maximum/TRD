#include <vector>

using namespace std;

vector<vector<int>>graph, inverted_graph;
vector<char> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i < graph[v].size(); ++i)
        if (!used[ graph[v][i] ]) dfs1(graph[v][i]);
    order.push_back(v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i < inverted_graph[v].size(); ++i)
        if (!used[ inverted_graph[v][i] ]) dfs2 (inverted_graph[v][i]);
}

int main() {
    int n;
    for (;;) {
        int a, b;
        // ... чтение очередного ребра (a,b) ...
        graph[a].push_back(b);
        inverted_graph[b].push_back(a);
    }
    used.assign(n, false);
    for (int i=0; i<n; ++i)
        if (!used[i]) dfs1 (i);

    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            component.clear();
        }
    }
}
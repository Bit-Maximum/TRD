#include <vector>
#include <set>

using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];
bool used[MAXN];
int timer = 0;
vector tin = vector<int>(MAXN, 0);
vector fup = vector<int>(MAXN, 0);
set<pair<int, int>> bridges;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (to == p) continue;
        if (used[to]) fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) bridges.insert(pair(v, to));
        } } }

void find_bridges() {
    for (int i=0; i < n; ++i)
        used[i] = false;
    for (int i=0; i < n; ++i)
        if (!used[i]) dfs(i);
}
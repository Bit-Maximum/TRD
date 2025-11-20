#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;
int MAXN = static_cast<int>(10e9);

vector<vector<int>> graph = vector<vector<int>>(MAXN);
vector used = vector<bool>(MAXN, false);
vector tin = vector<int>(MAXN, 0);
vector fup = vector<int>(MAXN, 0);
set<int> cutpts;
int timer = 0;

void dfs(int v, int prev_node = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (to == prev_node) continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && prev_node != -1)
                cutpts.insert(v);
            ++children;
        }
    }
    if (prev_node == -1 && children > 1)
        cutpts.insert(v);
}



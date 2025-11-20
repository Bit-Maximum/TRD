const int maxn = 1e5;
int component[maxn];

void dfs(int v, int num) {
    component[v] = num;
    for (int u : graph[v])
        if (!component[u])
            dfs(u, num);
}

// Main
int num = 0;
    for (int v = 0; v < n; v++)
        if (!component[v])
            dfs(v, ++num);
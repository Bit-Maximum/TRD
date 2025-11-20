const int maxn = 1e5;
bool used[maxn];

// возвращает -1, если цикл не нашелся, и вершину начала цикла в противном случае
int dfs(int v, int p = -1) {
    if (used[v]) {
        cout << "Graph has a cycle, namely:" << endl;
        return v;
    }
    used[v] = true;
    for (int u : g[v]) {
        if (u != p) {
            int k = dfs(u, v);
            if (k != -1) {
                cout << v << endl;
                if (k == v)
                    exit(0);
                return k;
            }
        }
    }
    return -1;
}

// Main
for (int v = 0; v < n; v++)
    if (!used[v])
        dfs(v);
//0-индексация
struct HLD{
    int timer;
    int n;
    vector<int> sz;
    vector<int> nxt;
    vector<int> in;
    vector<int> out;
    vector<int> h;
    vector<vector<int>> g;
    vector<int> par;
//необязательно
    vector<int> bck;
    SegmentTree st;
    void dfs_sz(int v) {
        sz[v] = 1;
        for (int& to : g[v]) {
            g[to].erase(find(g[to].begin(), g[to].end(), v));
            h[to] = h[v] + 1;
            par[to] = v;
            dfs_sz(to);
            sz[v] += sz[to];
            if (sz[to] > sz[g[v][0]]) {
                swap(g[v][0], to);
            }
        }
    }
    void dfs_hld(int v) {
        in[v] = timer++;
        bck[in[v]] = v;
        for (int to : g[v]) {
            nxt[to] = (to == g[v][0] ? nxt[v] : to);
            dfs_hld(to);
        }
        out[v] = timer;
    }
    HLD(vector<vector<int>>& gg) : st(gg.size()) {
        g = gg;
        n = g.size();
        par.resize(n);
        sz.resize(n);
        in.resize(n);
        out.resize(n);
        nxt.resize(n);
        h.resize(n);
        bck.resize(n);
        timer = 0;
        dfs_sz(0);
        dfs_hld(0);
    }
    bool isParent(int batya, int x) {
        return (in[batya] <= in[x] && out[x] <= out[batya]);
    }
    void addPath(int u, int v, ll val) {
        while (true) {
            if (nxt[u] == nxt[v]) {
                if (in[v] > in[u]) swap(u, v);
                st.upd(1, 0, n - 1, in[v], in[u], val);
                return;
            }
            if (!isParent(nxt[u], v)) {
                st.upd(1, 0, n - 1, in[nxt[u]], in[u], val);
                u = par[nxt[u]];
            }
            else if (!isParent(nxt[v], u)) {
                st.upd(1, 0, n - 1, in[nxt[v]], in[v], val);
                v = par[nxt[v]];
            }
            else {
                assert(false);
            }
        }
    }
    void addSubtree(int u, ll val) {
        st.upd(1, 0, n - 1, in[u], out[u] - 1, val);
    }
};

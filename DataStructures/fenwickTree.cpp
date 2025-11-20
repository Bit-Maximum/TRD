struct FenwickTree{
    vector<ll> tree;
    int n;
    void Add(int idx, ll add) {
        while(idx < n) {
            tree[idx] += add;
            idx = (idx | (idx + 1));
        }
    }
    ll Sum(int idx) {
        ll res = 0;
        while(idx >=0) {
            res += tree[idx];
            idx = (idx & (idx + 1)) -1;
        }
        return res;
    }
    ll Sum(int left, int right) {
        return Sum(right - 1) - Sum(left - 1);
    }
    FenwickTree(const vector<ll> &a = {}) {
        n = a.size();
        tree.resize(n);
        for(int i =0;i<n;++i) {
            Add(i, a[i]);
        }
    }
};
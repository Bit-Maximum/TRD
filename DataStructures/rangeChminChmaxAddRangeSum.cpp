ll inf = 1e18;
struct Node {
    ll max, min, second_max, second_min;
    int cnt_max, cnt_min, len;
    ll sum, push_add;
    Node(ll val = 0) : max(val), min(val), second_max(-inf), second_min(inf),
                       cnt_max(1), cnt_min(1), len(1), sum(val),
                       push_add(0) {
    }
    void Merge(const Node &l, const Node &r) {
        max = std::max(l.max, r.max);
        if (l.max == r.max) {
            second_max = std::max(l.second_max, r.second_max);
            cnt_max = l.cnt_max + r.cnt_max;
        } else {
            second_max = std::min(l.max, r.max);
            second_max = std::max({second_max, l.second_max, r.second_max});
            if (l.max > r.max) {
                cnt_max = l.cnt_max;
            } else {
                cnt_max = r.cnt_max;
            }
        }
        min = std::min(l.min, r.min);
        if (l.min == r.min) {
            second_min = std::min(l.second_min, r.second_min);
            cnt_min = l.cnt_min + r.cnt_min;
        } else {
            second_min = std::max(l.min, r.min);
            second_min = std::min({second_min, l.second_min, r.second_min});
            if (l.min < r.min) {
                cnt_min = l.cnt_min;
            } else {
                cnt_min = r.cnt_min;
            }
        }
        len = l.len + r.len;
        sum = l.sum + r.sum;
        push_add = 0;
    }
    void ApplyAdd(ll add) {
        max += add;
        second_max += add;
        min += add;
        second_min += add;
        sum += add * len;
        push_add += add;
    }
    void ApplyMin(ll val) {
        if (max > val) {
            sum -= (max - val) * cnt_max;
            if (max == second_min) {
                second_min = val;
            }
        }
        min = std::min(min, val);
        max = std::min(max, val);
    }
    void ApplyMax(ll val) {
        if (min < val) {
            sum += (val - min) * cnt_min;
            if (min == second_max) {
                second_max = val;
            }
        }
        max = std::max(max, val);
        min = std::max(min, val);
    }
};
struct SegmentTreeBeats {
    vector<Node> tree;
    int n;
    void Build(const vector<ll> &arr, int v, int tl, int tr) {
        if (tl + 1 == tr) {
            tree[v] = Node(arr[tl]);
            return;
        }
        int mid = (tl + tr) / 2;
        Build(arr, 2 * v, tl, mid);
        Build(arr, 2 * v + 1, mid, tr);
        tree[v].Merge(tree[2 * v], tree[2 * v + 1]);
    }
    SegmentTreeBeats(const vector<ll> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        Build(arr, 1, 0, n);
    }
    void Push(int v) {
        if (tree[v].push_add != 0) {
            tree[2 * v].ApplyAdd(tree[v].push_add);
            tree[2 * v + 1].ApplyAdd(tree[v].push_add);
            tree[v].push_add = 0;
        }
        if (tree[v].max < tree[2 * v].max) {
            tree[2 * v].ApplyMin(tree[v].max);
        }
        if (tree[v].max < tree[2 * v + 1].max) {
            tree[2 * v + 1].ApplyMin(tree[v].max);
        }
        if (tree[v].min > tree[2 * v].min) {
            tree[2 * v].ApplyMax(tree[v].min);
        }
        if (tree[v].min > tree[2 * v + 1].min) {
            tree[2 * v + 1].ApplyMax(tree[v].min);
        }
    }
    void Add(ll val, int l, int r, int v, int tl, int tr) {
        if (l >= tr || r <= tl) {
            return;
        }
        if (l <= tl && r >= tr) {
            tree[v].ApplyAdd(val);
            return;
        }
        Push(v);
        int mid = (tl + tr) / 2;
        Add(val, l, r, 2 * v, tl, mid);
        Add(val, l, r, 2 * v + 1, mid, tr);
        tree[v].Merge(tree[2 * v], tree[2 * v + 1]);
    }
    void ChMin(ll val, int l, int r, int v, int tl, int tr) {
        if (l >= tr || r <= tl || tree[v].max <= val) {
            return;
        }
        if (l <= tl && r >= tr && tree[v].second_max < val) {
            tree[v].ApplyMin(val);
            return;
        }
        Push(v);
        int mid = (tl + tr) / 2;
        ChMin(val, l, r, 2 * v, tl, mid);
        ChMin(val, l, r, 2 * v + 1, mid, tr);
        tree[v].Merge(tree[2 * v], tree[2 * v + 1]);
    }
    void ChMax(ll val, int l, int r, int v, int tl, int tr) {
        if (l >= tr || r <= tl || tree[v].min >= val) {
            return;
        }
        if (l <= tl && r >= tr && tree[v].second_min > val) {
            tree[v].ApplyMax(val);
            return;
        }
        Push(v);
        int mid = (tl + tr) / 2;
        ChMax(val, l, r, 2 * v, tl, mid);
        ChMax(val, l, r, 2 * v + 1, mid, tr);
        tree[v].Merge(tree[2 * v], tree[2 * v + 1]);
    }
    ll GetSum(int l, int r, int v, int tl, int tr) {
        if (l >= tr || r <= tl) {
            return 0;
        }
        if (l <= tl && r >= tr) {
            return tree[v].sum;
        }
        Push(v);
        int mid = (tl + tr) / 2;
        return GetSum(l, r, 2 * v, tl, mid) +
               GetSum(l, r, 2 * v + 1, mid, tr);
    }
};

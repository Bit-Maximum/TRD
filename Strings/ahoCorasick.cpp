namespace AhoCorasick {
    const int MAXN = 1000100;
    const int ALPH = 26;
    int size; // number of already included nodes; REQUIRED
    int h[MAXN]; // node height; OPTIONAL
    int root[MAXN]; // node's root; REQUIRED
    int char_ind[MAXN]; // node's string charected; REQUIRED
    int prev[MAXN]; // longest suffix; REQUIRED
    int prev_str[MAXN]; // previous string ending; OPTIONAL
    int is_str[MAXN]; // is this node a string ending; OPTIONAL
    int next[MAXN][ALPH]; // next node after this symbol; REQUIRED

    void AddNode(int ch, int c_root, int char_i) {
        h[size] = ch;
        root[size] = c_root;
        char_ind[size] = char_i;
        prev[size] = 0;
        prev_str[size] = 0;
        is_str[size] = -1;
        for (int i = 0; i < ALPH; ++i) {
            next[size][i] = -1;
        }
        ++size;
    }

    void Init() {
        size = 0;
        AddNode(0, 0, 0);
    }

    void AddString(const string& s, int string_ind) {
        int cn = 0;
        for (char c : s) {
            if (next[cn][c - 'a'] == -1) {
                AddNode(h[cn] + 1, cn, c - 'a');
                next[cn][c - 'a'] = size - 1;
            }
            cn = next[cn][c - 'a'];
        }
        is_str[cn] = string_ind;
    }

    void ConstructAho() {
        queue<int> que;
        // Insert all root's children into queue
        for (int i = 0; i < ALPH; ++i) {
            if (next[0][i] == -1) { next[0][i] = 0; }
            else { que.push(next[0][i]); }
        }
        // Go through the nodes with BFS, set their 'prev', 'prev_string' and 'next' values
        while (!que.empty()) {
            int cn = que.front();
            que.pop();
            prev[cn] = next[prev[root[cn]]][char_ind[cn]];
            if (prev[cn] == cn) { prev[cn] = 0; }
            if (is_str[prev[cn]] >= 0) { prev_str[cn] = prev[cn]; }
            else { prev_str[cn] = prev_str[prev[cn]]; }
            for (int i = 0; i < ALPH; ++i) {
                if (next[cn][i] == -1) { next[cn][i] = next[prev[cn]][i]; }
                else { que.push(next[cn][i]); }
            }
        }
    }
};
